#include <iostream> //input output stream

int main()
{
    //1번문제
    for(int i = 1; i <= 5; i++) 
    {
        for(int j = 1; j <= i; j++)
        {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }


    //2번문제
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 5; j >= i; j--)
        {
            std::cout << j << " ";
        }
        std::cout << "\n";
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
    }
}

