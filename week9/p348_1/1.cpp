#include "1.hpp" // 위에서 만든 헤더 파일을 포함시킵니다.

int main() {
    // 매개변수가 없는 경우 (모두 0으로 초기화됨)
    MyTime t1;                
    
    // 매개변수가 있는 경우
    MyTime t2(10, 30, 45, 500); 

    std::cout << "t1 (기본 초기화): ";
    t1.print();

    std::cout << "t2 (값 전달): ";
    t2.print();

    return 0;
}