#include <iostream>
#include <cstdlib>
#include <ctime>
#include "1.h"


void randomMap(int map[5][5])
{
    for(int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            map[i][j] = rand() % 2;
        }
    }

}

void printMap(int map[5][5]) 
{
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------" << std::endl;
}


void checkMap(int map[5][5]) {
    // 가로
    for (int i = 0; i < 5; i++) 
    {
        bool allSame = true;
        for (int j = 1; j < 5; j++) 
        {
            if (map[i][j] != map[i][0]) 
            {
                allSame = false;
                break;
            }
        }
        if (allSame) std::cout << "가로 " << i + 1 << "행이 모두 " << map[i][0] << "이다" << std::endl;
    }

    //세로
    for (int j = 0; j < 5; j++) {
        bool allSame = true;
        for (int i = 1; i < 5; i++) {
            if (map[i][j] != map[0][j]) {
                allSame = false;
                break;
            }
        }
        if (allSame) std::cout << "세로 " << j + 1 << "열이 모두 " << map[0][j] << "이다" << std::endl;
    }

       //대각선(＼)
    bool diag1Same = true;
    for (int i = 1; i < 5; i++) {
        if (map[i][i] != map[0][0]) {
            diag1Same = false;
            break;
        }
    }
    if (diag1Same) std::cout << "기본 대각선(＼)이 모두 " << map[0][0] << "이다" << std::endl;

    //대각선(／)
    bool diag2Same = true;
    for (int i = 1; i < 5; i++) {
        if (map[i][4 - i] != map[0][4]) {
            diag2Same = false;
            break;
        }
    }
    if (diag2Same) std::cout << "반대 대각선(／)이 모두 " << map[0][4] << "이다" << std::endl;
}
