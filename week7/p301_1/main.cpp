#include <iostream>
#include "MyTime.hpp"

int main() {
    MyTime t1, t2, t3;

    
    std::cout << "--- t1 입력 ---" << std::endl;
    t1.read();
    t1.print();

    
    std::cout << "\n--- t2 변환 (3661.5초) ---" << std::endl;
    t2.convert(3661.5);
    t2.print();

    
    std::cout << "\n--- t1 + t2 결과 ---" << std::endl;
    t3 = t1.add(t2);
    t3.print();

    
    std::cout << "\n--- t3 리셋 결과 ---" << std::endl;
    t3.reset();
    t3.print();

    return 0;
}
