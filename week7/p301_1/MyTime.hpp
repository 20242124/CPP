#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>
#include <iomanip>

class MyTime {
private:
    // 문제 1-(1): 멤버 변수들을 private으로 처리
    int hours;
    int minutes;
    int seconds;
    int milliseconds;

public:
    // 문제 1-(1): 모든 멤버 함수는 public
    inline void convert(double duration);
    inline void print();
    inline MyTime add(MyTime t);
    inline void reset();
    inline void read(); // 문제 1-(4)
};


#include "MyTime.cpp"

#endif
