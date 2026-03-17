#include <iostream> //input output stream

int main()
{
    //1번문제
    for(int i = 1; i <= 5; ++i) // 초기값은 1. i가 5이하면 1을 계속 더해라.
    {
        //std::cout << i << "\n"; //1을 출력하라. \n = 줄을 바꿔라.
        for(int j = 1; j <= i; ++j)
        {
            std::cout << j;
        }
        std::cout << "\n";
        printf("\n");
    }


    //2번문제
    for(int i = 1; i <= 5; ++i) // 초기값은 1. i가 5이하면 1을 계속 더해라.
    {
        //std::cout << i << "\n"; //1을 출력하라. \n = 줄을 바꿔라.
        for(int j = 5; j >= i; --j)
        {
            std::cout << j;
        }
        std::cout << "\n";
        printf("\n");
    }

    //3번문제
    for(int i = 1; i <= 5; i++) 
    {
        for(int k = 1; k <= 5 - i; k++)
        {
            std::cout << "  "; 
        }
        for(int j = i; j >= 1; j--)
        {
            std::cout << j << " ";
        }
        std::cout << "\n";
        printf("\n");
    }
    //4번문제
    for(int i = 1; i <= 5; i++)
    {
        for(int k = 1; k <= 5 - i; k++)
        {
            std::cout << "  ";
        }

        for(int j = i; j >= 1; j--)
        {
            std::cout << j << " ";
        }

        for(int m = 2; m <= i; m++)
        {
            std::cout << m << " ";
        }
        std::cout << "\n";
        printf("\n");
    }
}

