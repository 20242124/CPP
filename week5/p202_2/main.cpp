#include <iostream>
#include <cstdlib>
#include <ctime>
#include "1.h" // 정의된 함수들을 사용하기 위해 포함

int main() {
    std::srand((unsigned int)std::time(NULL)); // 랜덤 시드 초기화

    int map[5][5];

    randomMap(map);
    printMap(map);
    checkMap(map);

    return 0;
}
