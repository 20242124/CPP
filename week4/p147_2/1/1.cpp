#include <iostream>
#include <algorithm>
#include <string>

std::string reverse(std::string s)
{
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    std::string s;
    std::cout << "숫자를 입력하세요: ";
    std::cin >> s;

    std::cout << reverse(s) << std::endl;
}