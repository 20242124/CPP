#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <iomanip>

using namespace std;

// (6) 랭킹 정보를 위한 구조체
struct RankRecord {
    char name[20];
    int size;
    int moveCount;
    int seconds;
};

class PuzzleGame {
private:
    int size;
    vector<vector<int>> board;
    vector<vector<int>> initialBoard;
    int blankR, blankC;
    int moveCount;
    string moves; // (2) 리플레이를 위한 이동 경로 저장
    time_t startTime;
    int elapsedBeforeSave;

public:
    PuzzleGame() : size(4), moveCount(0), elapsedBeforeSave(0) {}

    // (1) 맵 크기 확장 및 초기화
    void init(int s) {
        size = s;
        board.assign(size, vector<int>(size));
        int num = 1;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                board[i][j] = (num < size * size) ? num++ : 0;
            }
        }
        blankR = size - 1;
        blankC = size - 1;
        shuffle();
        
        initialBoard = board; // (2) 리플레이용 초기 상태 저장
        moves = "";
        moveCount = 0;
        elapsedBeforeSave = 0;
        startTime = time(NULL);
    }

    void shuffle() {
        srand(static_cast<unsigned>(time(NULL)));
        int shuffles = 0;
        while (shuffles < 500) {
            char dirs[] = {'w', 'a', 's', 'd'};
            if (move(dirs[rand() % 4], false)) shuffles++;
        }
    }

    // (5) 그림 퍼즐 기능: 숫자를 문자로 변환
    char tileToChar(int val) {
        return (val == 0) ? ' ' : static_cast<char>('A' + val - 1);
    }

    void print() {
        int currentElapsed = static_cast<int>(time(NULL) - startTime) + elapsedBeforeSave;
        cout << "\n[ 시간: " << currentElapsed << "초 | 이동: " << moveCount << "회 ]" << endl;
        
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) cout << "+---";
            cout << "+" << endl;
            for (int j = 0; j < size; ++j) {
                cout << "| " << tileToChar(board[i][j]) << " ";
            }
            cout << "|" << endl;
        }
        for (int j = 0; j < size; ++j) cout << "+---";
        cout << "+" << endl;
    }

    bool move(char cmd, bool record = true) {
        int nr = blankR, nc = blankC;
        switch (tolower(cmd)) {
            case 'w': nr--; break;
            case 's': nr++; break;
            case 'a': nc--; break;
            case 'd': nc++; break;
            default: return false;
        }

        if (nr >= 0 && nr < size && nc >= 0 && nc < size) {
            swap(board[blankR][blankC], board[nr][nc]);
            blankR = nr;
            blankC = nc;
            if (record) {
                moves += cmd;
                moveCount++;
            }
            return true;
        }
        return false;
    }

    bool isSolved() {
        int num = 1;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i == size - 1 && j == size - 1) return board[i][j] == 0;
                if (board[i][j] != num++) return false;
            }
        }
        return true;
    }

    // (3) 게임 저장 기능
    void save() {
        ofstream out("puzzle_save.dat", ios::binary);
        if (!out) return;

        elapsedBeforeSave += static_cast<int>(time(NULL) - startTime);
        
        out.write((char*)&size, sizeof(size));
        out.write((char*)&blankR, sizeof(blankR));
        out.write((char*)&blankC, sizeof(blankC));
        out.write((char*)&moveCount, sizeof(moveCount));
        out.write((char*)&elapsedBeforeSave, sizeof(elapsedBeforeSave));

        for(auto& row : board) out.write((char*)row.data(), sizeof(int) * size);
        for(auto& row : initialBoard) out.write((char*)row.data(), sizeof(int) * size);

        int moveLen = moves.length();
        out.write((char*)&moveLen, sizeof(moveLen));
        out.write(moves.c_str(), moveLen);
        
        out.close();
        cout << ">> 게임이 저장되었습니다." << endl;
    }

    // (4) 저장된 게임 이어가기
    bool load() {
        ifstream in("puzzle_save.dat", ios::binary);
        if (!in) return false;

        in.read((char*)&size, sizeof(size));
        board.assign(size, vector<int>(size));
        initialBoard.assign(size, vector<int>(size));

        in.read((char*)&blankR, sizeof(blankR));
        in.read((char*)&blankC, sizeof(blankC));
        in.read((char*)&moveCount, sizeof(moveCount));
        in.read((char*)&elapsedBeforeSave, sizeof(elapsedBeforeSave));

        for(auto& row : board) in.read((char*)row.data(), sizeof(int) * size);
        for(auto& row : initialBoard) in.read((char*)row.data(), sizeof(int) * size);

        int moveLen;
        in.read((char*)&moveLen, sizeof(moveLen));
        char* buf = new char[moveLen + 1];
        in.read(buf, moveLen);
        buf[moveLen] = '\0';
        moves = buf;
        delete[] buf;

        in.close();
        startTime = time(NULL);
        return true;
    }

    // (2) 리플레이 기능
    void replay() {
        vector<vector<int>> currentBoard = board;
        int curR = blankR, curC = blankC;

        board = initialBoard;
        // 초기 blank 위치 찾기
        for(int i=0; i<size; i++)
            for(int j=0; j<size; j++)
                if(board[i][j] == 0) { blankR = i; blankC = j; }

        cout << "\n--- 리플레이 시작 ---" << endl;
        print();
        for (char m : moves) {
            cout << "이동: " << m << endl;
            move(m, false);
            print();
        }
        cout << "--- 리플레이 종료 ---" << endl;

        board = currentBoard;
        blankR = curR; blankC = curC;
    }

    void handleRanking(string name) {
        vector<RankRecord> ranks;
        RankRecord newR;
        size_t len = name.copy(newR.name, 19);
        newR.name[len] = '\0';
        newR.size = size;
        newR.moveCount = moveCount;
        newR.seconds = elapsedBeforeSave + static_cast<int>(time(NULL) - startTime);

        ifstream in("ranking.dat", ios::binary);
        RankRecord temp;
        if(in) {
            while(in.read((char*)&temp, sizeof(RankRecord))) ranks.push_back(temp);
            in.close();
        }

        ranks.push_back(newR);
        sort(ranks.begin(), ranks.end(), [](const RankRecord& a, const RankRecord& b) {
            return a.seconds < b.seconds; // 시간 짧은 순
        });

        ofstream out("ranking.dat", ios::binary | ios::trunc);
        for (int i = 0; i < ranks.size() && i < 10; ++i) {
            out.write((char*)&ranks[i], sizeof(RankRecord));
        }
        out.close();
    }

    static void showRanking() {
        ifstream in("ranking.dat", ios::binary);
        if (!in) { cout << "\n>> 기록이 없습니다." << endl; return; }
        cout << "\n========= TOP 10 RANKING =========" << endl;
        RankRecord r;
        int i = 1;
        while (in.read((char*)&r, sizeof(RankRecord))) {
            cout << i++ << "위 | " << setw(8) << r.name << " | " << r.size << "x" << r.size 
                 << " | " << r.moveCount << "회 | " << r.seconds << "초" << endl;
        }
        in.close();
    }
};

int main() {
    PuzzleGame game;
    int choice;

    cout << "==== C++ PUZZLE MASTER ====\n1. 새 게임\n2. 이어하기\n3. 랭킹 보기\n선택: ";
    cin >> choice;

    if (choice == 3) { PuzzleGame::showRanking(); return 0; }
    if (choice == 2 && !game.load()) {
        cout << "저장된 게임이 없어 새 게임을 시작합니다." << endl;
        choice = 1;
    }
    if (choice == 1) {
        int s; cout << "크기 선택(3-5): "; cin >> s;
        game.init(s);
    }

    while (true) {
        game.print();
        if (game.isSolved()) {
            cout << "\n 퍼즐을 풀었습니다. " << endl;
            string name; cout << "이름 입력: "; cin >> name;
            game.handleRanking(name);
            char rep; cout << "리플레이를 보시겠습니까? (y/n): "; cin >> rep;
            if (tolower(rep) == 'y') game.replay();
            break;
        }

        cout << "W/A/S/D: 이동, X: 저장 및 종료, Q: 그냥 종료 >> ";
        char cmd; cin >> cmd;
        if (tolower(cmd) == 'q') break;
        if (tolower(cmd) == 'x') { game.save(); break; }
        game.move(cmd);
    }

    return 0;
}