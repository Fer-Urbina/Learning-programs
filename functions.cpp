/*
#include <iostream>
#include <string>

int sum (int a, int b);
double sum(double a, double b);
float sum(float a, float b, float c);

int main ()
{
    std::cout << sum(4, 3) << std::endl;
    std::cout << sum(4.4, 3.3) << std::endl;
    std::cout << sum(4.4, 3.3, 2.2);
    return 0;
}

int sum(int a, int b)
{
    return a + b;
}

double sum(double a, double b)
{
    return a + b;
}

float sum(float a, float b, float c)
{
    return a + b + c;
}
*/

//PROGRAM TO FIND A PRIME NUMBER
/*
#include <iostream>
#include <string>

bool isPrimeNumber(int number)
{
    bool isPrimeFlag = true;
    for (int i = 2; i < number; i++)
    {
        if(number % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main ()
{
    for (int i = 1; i <= 1000; i++)
    {
        bool isPrime = isPrimeNumber(i);
        if (isPrime)
            std::cout << i << " is Prime number\n";
        
    }
    return 0;
} */


/*
#include <iostream>

int getMin(int numbers[],int size)
{
    int min = numbers[0];
    for (int i = 1; i < size; i++)
    {
        if (numbers[i] < min)
            min = numbers[i];
    }
    return min;
}

int getMax(int numbers[],int size)
{
    int max = numbers[0];
    for (int i = 1; i < size; i++)
    {
        if (numbers[i] > max)
            max = numbers[i];
    }
    return max;
}

void getMinAndMax (int numbers[], int size, int *min, int *max)
{
    for (int i = 1; i < size; i++)
    {
        if (numbers[i] > *max)
            *max = numbers[i];
        if (numbers[i] < *min)
            *min = numbers[i];
    }
}

int main ()
{
    int numbers[5] = {5,4,-2,29,6};
    /*std::cout << "Min is " << getMin(numbers, 5) << std::endl;
    std::cout << "Max is " << getMax(numbers, 5) << std::endl;
    int min = numbers[0];
    int max = numbers[0];

    getMinAndMax(numbers, 5, &min, &max);
    std::cout << "Min is " << min << std::endl;
    std::cout << "Max is " << max << std::endl;

    return 0;
}
*/

//SUM numbers between m - n

#include <iostream>

int recursive_sum(int m, int n)
{   
    if (m == n)
        return m;
    return m + recursive_sum(m + 1, n);
}

int main ()
{
    int m = 1, n = 5;
    std::cout << "Sum = " << recursive_sum(m, n);

    /* int sum = 0;
    for (int i = m; i <= n; i++)
    {
        sum += i;
    }
    std::cout << "Sum is " << sum; */

    return 0;
}
