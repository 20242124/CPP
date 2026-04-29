#include "1.hpp"

int main() {
    MyTime t1;                
    MyTime t2(10, 30, 45, 500); 
    
    MyTime t3(3665.5);

    std::cout << "t1 (기본 초기화): ";
    t1.print();

    std::cout << "t2 (값 전달): ";
    t2.print();

    std::cout << "t3 (double 시간 전달): ";
    t3.print();

    return 0;
}