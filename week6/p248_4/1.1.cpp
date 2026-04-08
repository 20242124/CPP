#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;


const int MAX_ROW = 40;
const int MAX_COL = 80;

static int MineMapMask[MAX_ROW][MAX_COL];  
static int MineMapLabel[MAX_ROW][MAX_COL]; 

int R, C, num_mines;

void initGame() {
    srand((unsigned int)time(NULL));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            MineMapMask[i][j] = 0;
            MineMapLabel[i][j] = 0;
        }
    }

    int placed = 0;
    while (placed < num_mines) {
        int r = rand() % R;
        int c = rand() % C;
        if (MineMapLabel[r][c] != -1) {
            MineMapLabel[r][c] = -1;
            placed++;
        }
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (MineMapLabel[r][c] == -1) continue;
            int count = 0;
            for (int i = r - 1; i <= r + 1; i++) {
                for (int j = c - 1; j <= c + 1; j++) {
                    if (i >= 0 && i < R && j >= 0 && j < C) {
                        if (MineMapLabel[i][j] == -1) count++;
                    }
                }
            }
            MineMapLabel[r][c] = count;
        }
    }
}


void drawMap(bool reveal) {
    system("cls");
    cout << "   ";
    for (int j = 0; j < C; j++) cout << setw(2) << j % 10;
    cout << "\n";

    for (int i = 0; i < R; i++) {
        cout << setw(2) << i << "|"; 
        for (int j = 0; j < C; j++) {
            if (!reveal && MineMapMask[i][j] == 0) cout << ". ";     
            else if (!reveal && MineMapMask[i][j] == 2) cout << "P "; 
            else {
                if (MineMapLabel[i][j] == -1) cout << "* ";          
                else if (MineMapLabel[i][j] == 0) cout << "  ";      
                else cout << MineMapLabel[i][j] << " ";              
            }
        }
        cout << "|\n";
    }
}


void dig(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return;
    if (MineMapMask[r][c] == 1 || MineMapMask[r][c] == 2) return; 

    MineMapMask[r][c] = 1; 

    if (MineMapLabel[r][c] == 0) { 
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                dig(r + i, c + j);
            }
        }
    }
}


bool checkWin() {
    int unOpened = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (MineMapMask[i][j] != 1) unOpened++;
        }
    }
    return (unOpened == num_mines);
}

int main() {
    cout << "맵의 크기 입력 (행 열, 최대 40 80): ";
    cin >> R >> C;
    cout << "지뢰의 개수 입력: ";
    cin >> num_mines;

    if (R > MAX_ROW || C > MAX_COL) {
        cout << "최대 크기를 초과했습니다.\n";
        return 1;
    }

    initGame();
    string line;
    getline(cin, line); 

    while (true) {
        drawMap(false);
        cout << "\n입력 (행 열 / 깃발은 p 행 열): ";
        getline(cin, line);

        stringstream ss(line);
        string cmd;
        int r, c;

        ss >> cmd;
        if (cmd == "p" || cmd == "P") {
            ss >> r >> c;
            if (r >= 0 && r < R && c >= 0 && c < C) {
                MineMapMask[r][c] = (MineMapMask[r][c] == 2) ? 0 : 2;
            }
        } else {
            r = stoi(cmd);
            ss >> c;
            if (r >= 0 && r < R && c >= 0 && c < C) {
                if (MineMapLabel[r][c] == -1) {
                    drawMap(true);
                    cout << "\n지뢰를 밟았습니다! Game Over...\n";
                    break;
                }
                dig(r, c);
            }
        }

        if (checkWin()) {
            drawMap(true);
            cout << "\n축하합니다! 모든 지뢰를 찾았습니다 (Victory!)\n";
            break;
        }
    }

    return 0;
}