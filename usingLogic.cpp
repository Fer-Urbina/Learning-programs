//Program to multiply 2 numbers without using the * operator
/*#include <iostream>

int main()
{
    long num1, num2, product = 0;

    std::cout << "Enter both numbers: ";
    std::cin >> num1 >> num2;

    while (num2 > 0)
    {
        product += num1;
        num2--;
    } 
    std::cout << std::endl << "the product of " << num1 << " and " << num2 << " is: " << product;

    return 0;
} */

#include <iostream>

int main ()
{
    int n;
    std::cout << "Ingrese un numero del 1 al 100: ";
    std::cin >> n;

    if (n >= 0 && n <= 100)
    {
        std::cout << "Contando desde " << n << "hasta 100." << std::endl;
        for (int i = n; i < 100; i++)
        {
            std::cout << i << std::endl;
        } 
    } else
    {
        std::cout << "Numero ingresado invalido" << std::endl;
    }
    return 0;
}