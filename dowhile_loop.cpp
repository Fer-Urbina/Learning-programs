//Entering an ATM Pin

/* #include <iostream>

int main ()
{
    int UsersPin = 1234, pin, errorCounter = 0;

    do 
    {
        std::cout << "PIN: ";
        std::cin >> pin;
        if (pin != UsersPin)
            errorCounter++;
    } while (errorCounter < 3 && pin != UsersPin);

    if (errorCounter < 3)
    std::cout << "Loading...";
    else {
        std::cout << "Blocked...";
    }
} */

#include <string>
#include <iostream>

int main ()
{
    //atleast once
    std::string password = "hellotacos123";
    std::string guess;
    
    while(guess != password)
    {
        std::cout << "Guess the password: ";
        std::cin >> guess;
    }
    
    return 0;
}