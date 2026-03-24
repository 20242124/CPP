#include <iostream>
#include <algorithm>
#include <string>

int main() {
    //함수 정의
    auto my_reverse = [](std::string s) {
        std::reverse(s.begin(), s.end());
        return s;
    };

    std::string s;
    std::cout << "숫자를 입력하세요: ";
    std::cin >> s;

    // 변수처럼 호출
    std::cout << "결과: " << my_reverse(s) << std::endl;

    return 0;
}
