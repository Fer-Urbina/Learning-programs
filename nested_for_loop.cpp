//It draws a triangle/invereted with any symbol you enter
#include <iostream>
#include <string>
#include <iomanip>

int main ()
{
    int length;
    std::cout << "Length: ";
    std::cin >> length;
    char symbol;
    std::cout << "Symbol";
    std::cin >> symbol;

    for (int i = 1; i <= length; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << std::setw(2) << symbol;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;

    for (int i = length; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << std::setw(2) << symbol;
        }
        std::cout << std::endl;
    }

    return 0;   
}