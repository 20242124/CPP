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

    //조건: 10단위 이상에서 1이면 숫자 생략
    if (a > 0) {
        if (a > 1) std::cout << a;
        std::cout << "만 ";
    }


    if (b > 0) {
        if (b > 1) std::cout << b; 
        std::cout << "천 ";
    }

    
    if (c > 0) {
        if (c > 1) std::cout << c; 
        std::cout << "백 ";
    }

   
    if (d > 0) {
        if (d > 1) std::cout << d; 
        std::cout << "십 ";
    }

    
    if (e > 0) {
        std::cout << e;
    }

    std::cout << std::endl;

    return 0;
}
