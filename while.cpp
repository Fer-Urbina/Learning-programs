/* #include <iostream>

int main ()
{
    //Reversing number

    int number, reversedNumber = 0; //0
    std::cout << "Number: ";
    std::cin >> number;//12

    while(number != 0)
    {
        reversedNumber *= 10;
        //int lastDigit = number % 10;
        reversedNumber += number % 10;
        number /= 10;
    }

    std::cout << "Reversed: " << reversedNumber;

    return 0;
} */

//CALCULATE THE AVERAGE OF 5 NUMBERS ENTERED BY THE USER
/* 
#include <iostream>

int main()
{
    int salaries[5];
    int sum = 0;

    for (int i = 0; i < 5; i++)
    {   
        std::cout << "Enter salary # " << i + 1 << ": ";
        std::cin >> salaries[i];
        sum += salaries[i];
    }

    double average = (double)sum / 5;

    std::cout << "The average of the 5 salaries: " << average << std::endl;

    return 0;
}
*/

//CALCULATE THE AVERAGE OF N NUMBERS ENTERED BY THE USER
/*
#include <iostream>

int main ()
{
    int n;
    std::cout << "Enter the number of salaries you want to calculate: ";
    std::cin >> n;
    
    int salaries[n];

    for (int i = 0; i < n; i++)
    {   
        std::cout << "Enter the salary: ";
        std::cin >> salaries[i];
    }

    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += salaries[i];
    }

    double average = sum / n;

    std::cout << "The average of the salaries entered is: " << average << std::endl;

    return 0;
}
*/
/* 
//FINDING THE SUM OF THE ELEMENTS INSIDE A VECTOR USING ACCUMULATE FUNCTION

#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Use std::accumulate to calculate the sum of the elements in the vector
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    std::cout << "Sum of elements in the vector: " << sum << std::endl;
    return 0;
}
*/

#include <iostream>

int main ()
{
    int number, lastDigit, reversedNum = 0;
    std::cout << "Enter a number: ";
    std::cin >> number;

    while (number != 0)
    {
        reversedNum *= 10;
        reversedNum += number % 10;
        number /= 10;
    }

    std::cout << "The reversed number is: " << reversedNum;
    
    return 0;
}


