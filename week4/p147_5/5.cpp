#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int people, bullets, n;

    // 1. 게임 설정 입력
    cout << "--- 러시안 룰렛 설정 ---" << endl;
    cout << "사람 수 입력 : "; cin >> people;
    cout << "총알 수 입력 : "; cin >> bullets;
    cout << "탄창 칸 수(n연발) : "; cin >> n;

    // 총알이 탄창보다 많으면 무한 루프에 빠지므로 방지.
    if (bullets > n) {
        cout << "\n오류: 총알이 탄창 칸 수보다 많을 수 없습니다!" << endl;
        return 1; 
    }

    // 2. 탄창 준비 및 총알 장전
    vector<int> gun(n, 0); // n개의 칸을 모두 0(빈칸)으로 생성
    srand(time(0));        // 랜덤 설정

    int loaded = 0;
    while (loaded < bullets) {
        int pos = rand() % n;
        if (gun[pos] == 0) { // 이미 총알이 들어있는 곳이 아닐 때만
            gun[pos] = 1;    // 총알 장전
            loaded++;
        }
    }

    cout << "\n--- 게임을 시작합니다! ---" << endl;

    // 3. 게임 진행 변수 초기화
    int current_chamber = 0; // 현재 탄창의 위치 (0 ~ n-1)
    int current_player = 1;  // 현재 순서인 사람 (1 ~ people)
    int hits = 0;            // 지금까지 발사된 총알 개수

    // 모든 총알이 소진될 때까지 반복
    while (hits < bullets) {
        cout << "플레이어 " << current_player << "이 방아쇠를 당긴다 ";

        // 4. 당첨 판정
        if (gun[current_chamber] == 1) {
            cout << "맞았습니다." << endl;
            hits++; // 발사된 총알 카운트 증가
        } else {
            cout << "안 맞았습니다." << endl;
        }

        // 5. 순서 업데이트
        
        // 탄창 한 칸 돌리기: 마지막 칸이면 다시 처음(0)으로
        current_chamber++;
        if (current_chamber >= n) current_chamber = 0;

        // 플레이어 순서 넘기기: 마지막 번호면 다시 1번으로
        current_player++;
        if (current_player > people) current_player = 1;
    }

    cout << "\n모든 총알 " << bullets << "발이 소진되었습니다. 게임 종료합니다." << endl;

    return 0;
}