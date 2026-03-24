#include <iostream>
#include <algorithm>
#include <string>

std::string my_reverse(std::string s);

int main() {
    std::string s;
    std::cout << "숫자를 입력하세요: ";
    std::cin >> s;

    // 호출
    std::cout << "결과: " << my_reverse(s) << std::endl;
    return 0;
}

//정의
std::string my_reverse(std::string s) {
    std::reverse(s.begin(), s.end());
    return s;
}
