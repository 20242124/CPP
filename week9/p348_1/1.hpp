#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>

class MyTime {
    int hour, min, sec, milsec;

public:
    // 문제 1번: 초기화 리스트를 사용한 생성자
    MyTime(int h = 0, int m = 0, int s = 0, int ms = 0) 
        : hour(h), min(m), sec(s), milsec(ms) 
    {
    }

    void print() {
        std::cout << hour << "시 " << min << "분 " << sec << "초 " << milsec << "ms" << std::endl;
    }
};

#endif