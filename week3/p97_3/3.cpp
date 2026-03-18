#include <iostream>

int main() {
    int n;
    std::cout << "정수 n을 입력하세요: ";
    
    if (!(std::cin >> n)) {
        return 0;
    }

    double pi_sum = 0.0;
    double sign = 1.0;

    
    for (int i = 0; i <= n; i++) {
        double denominator = 2.0 * i + 1.0;
        pi_sum += sign / denominator;
        sign = -sign;
    }

    double final_pi = 4.0 * pi_sum;

    
    std::cout.precision(10);           // 소수점 아래 10자리까지 표시 설정
    std::cout.setf(std::ios::fixed);   // 소수점 자리를 고정해서 출력

    std::cout << "n이 " << n << "일 때, pi의 근사값: " << final_pi << std::endl;

    return 0;
}
