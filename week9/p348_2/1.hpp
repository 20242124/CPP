#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>

class MyTime {
    int hour, min, sec, milsec;

public:
    // 1번 초기화 리스트를 사용한 생성자
    MyTime(int h = 0, int m = 0, int s = 0, int ms = 0) 
        : hour(h), min(m), sec(s), milsec(ms) 
    {
    }

    // 2번 실수형 시간을 입력받는 생성자 (함수 중복)
    MyTime(double duration) {
        int total_sec = (int)duration;  
        
        hour = total_sec / 3600; 
        min = (total_sec % 3600) / 60; 
        sec = total_sec % 60;
        
        milsec = (int)((duration - total_sec) * 1000); 
    }

    void print() {
        std::cout << hour << "시 " << min << "분 " << sec << "초 " << milsec << "ms" << std::endl;
    }
};

#endif