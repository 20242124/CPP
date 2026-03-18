#include <iostream>


int main() {
    int n;
    std::cout << "1000 미만의 정수를 입력하세요: ";
    std::cin >> n;

    
    int a = (n / 10000) % 10; 
    int b = (n / 1000) % 10;  
    int c = (n / 100) % 10;   
    int d = (n / 10) % 10;    
    int e = n % 10;           


    if (a > 0) std::cout << a << "만 ";
    if (b > 0) std::cout << b << "천 ";
    if (c > 0) std::cout << c << "백 ";
    if (d > 0) std::cout << d << "십 ";
    if (e > 0) std::cout << e;

    std::cout << std::endl;

    return 0;
}
