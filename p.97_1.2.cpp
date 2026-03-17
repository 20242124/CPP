#include <iostream> //input output stream

int main()
{
    for(int i = 1; i <= 5; ++i) // 초기값은 1. i가 5이하면 1을 계속 더해라.
    {
        //std::cout << i << "\n"; //1을 출력하라. \n = 줄을 바꿔라.
        for(int j = 5; j >= i; --j)
        {
            std::cout << j;
        }
        std::cout << "\n";
    }
}
