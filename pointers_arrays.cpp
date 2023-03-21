/*
#include <iostream>

int main ()
{
    int luckyNumbers[5];
    //std::cout << luckyNumbers << std::endl;
    //std::cout << &luckyNumbers[0] << std::endl;
    //std::cout << luckyNumbers[2] << std::endl;
    //std::cout << *(luckyNumbers + 2) << std::endl; 

    for (int i = 0; i <= 4; i++)
    {
        std::cout << "Number: ";
        std::cin >> luckyNumbers[i];
    }
    
    for (int i = 0; i <= 4; i++)
    {
        std::cout << *(luckyNumbers+1) << "  ";
    }
    return 0;
} 
*/
/* 
#include <iostream>
#include <string>

int main ()
{
    int *p_number1{nullptr};
    int *p_fractional_number1{nullptr};

    //Pointers to different variables are of the same size
    std::cout << "sizeof(int) : " << sizeof(int) << std::endl;
    std::cout << "sizeof(double) : " << sizeof(double) << std::endl;
    std::cout << "sizeof(double*) : " << sizeof(double*) << std::endl;
    std::cout << "sizeof(int*) : " << sizeof(int*) << std::endl;
    std::cout << "sizeof(inp_number1) : " << sizeof(p_number1) << std::endl;
    std::cout << "sizeof(p_fractional_number1) : " << sizeof(p_fractional_number1) << std::endl; // 4

    int int_var {43};
    int *p_int{&int_var};//The adderss of operator (&);
    
    std::cout << "Int_var : " << int_var << std::endl;
    std::cout << "p_int (Address in memory) : " << p_int << std::endl;

    //Dereferencing a pointer
    int *p_int2 {nullptr};
    int int_data {56};
    p_int2 = &int_data;

    std::cout << "value : " << p_int2 << std::endl; // Dereferencing a pointer



    return 0;
    
} */

#include <iostream>
#include <string>

int main ()
{
    const char *meessage {"Hello World!"};
    std::cout << "Message : " << meessage << std::endl; 
    std::cout << "Message : " << *meessage << std::endl; 

    char message1[] {"Hello World!"};
    message1[0] = 'B';
    std::cout << "message : " << message1 << std::endl;

    return 0;

}
