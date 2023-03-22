#include <iostream>

int main ()
{
    int number, lastDigit, reversedNum = 0;
    std::cout << "Enter a number: ";
    std::cin >> number;

    while (number > 0)
    {
        reversedNum *= 10;
        reversedNum += number % 10;
        number /= 10;
    }

    std::cout << "The reversed number is: " << reversedNum;
    
    return 0;
}