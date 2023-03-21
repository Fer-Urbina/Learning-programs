#include <iostream>
#include <iomanip>

int main()
{
    float num1, num2;
    char operation;

    std::cout << "***Fernando's Calculator***";
    std::cin >> num1 >> operation >> num2;

    switch (operation)
    {
    case '-':
        std::cout << num1 << operation << num2 << "=" << num1 - num2;
        break;
    
    case '+':
        std::cout << num1 << operation << num2 << "=" << num1 + num2;
        break;

    case '/':
        std::cout << num1 << operation << num2 << "=" << num1 / num2;
        break;

    case '*':
        std::cout << num1 << operation << num2 << "=" << num1 * num2;
        break;

    case '%':
        bool isNumInt, isNum2Int;
        isNumInt = ((int)num1==num1);//
        isNum2Int = ((int)num2==num2);

        if(isNumInt && isNum2Int)
            std::cout << num1 << operation << num2 << "=" << (int)num1 % (int)num2;
        else
            std::cout << "Not valid";
        break;
    default:std::cout << "Not valid operation!" << std::endl;
    }
    
    return 0;
}