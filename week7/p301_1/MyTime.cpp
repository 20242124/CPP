#include <iostream>
#include <iomanip>


inline void MyTime::convert(double duration) {
    long long total_ms = (long long)(duration * 1000);
    milliseconds = total_ms % 1000;
    long long total_sec = total_ms / 1000;
    seconds = total_sec % 60;
    long long total_min = total_sec / 60;
    minutes = total_min % 60;
    hours = total_min / 60;
}

// 문제 1-(3): cout과 setfill, setw를 이용한 형식 출력
inline void MyTime::print() {
    std::cout << std::setfill('0') 
              << std::setw(2) << hours << ":"
              << std::setw(2) << minutes << ":"
              << std::setw(2) << seconds << ":"
              << std::setw(3) << milliseconds << std::endl;
}


inline MyTime MyTime::add(MyTime t) {
    MyTime sum;
    int carry = 0;

    sum.milliseconds = (this->milliseconds + t.milliseconds) % 1000;
    carry = (this->milliseconds + t.milliseconds) / 1000;

    sum.seconds = (this->seconds + t.seconds + carry) % 60;
    carry = (this->seconds + t.seconds + carry) / 60;

    sum.minutes = (this->minutes + t.minutes + carry) % 60;
    carry = (this->minutes + t.minutes + carry) / 60;

    sum.hours = this->hours + t.hours + carry;
    return sum;
}


inline void MyTime::reset() {
    hours = minutes = seconds = milliseconds = 0;
}

// 문제 1-(4): cin을 사용
inline void MyTime::read() {
    std::cout << "시간 입력 (시 분 초 밀리초): ";
    std::cin >> hours >> minutes >> seconds >> milliseconds;
}
