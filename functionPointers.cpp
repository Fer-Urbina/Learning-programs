#include <iostream>

int main ()
{
    int Pin, userPin = 123, errorCounter = 0;

    do
    {
        std::cout << "Enter PIN: ";
        std::cin >> Pin;
        if (Pin != userPin)
            errorCounter++;
        
    } while (errorCounter < 3 && Pin != userPin);

    if (errorCounter < 3)
        std::cout << "Loading...";
    else 
    {
        std::cout << "Blocked";
    }

    return 0;
    
}