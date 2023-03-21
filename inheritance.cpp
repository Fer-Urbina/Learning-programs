/* #include <iostream>
#include <string>

int main ()
{   
    int max {};

    int a {200};
    int b {35};

    std::cout << std::endl;
    std::cout << " " << std::endl;

    max = (a > b)? a : b; //if a > b, then max = a, else max = b

    std::cout << "max : " << max << std::endl;

    return 0;  
}
*/

/*
#include <iostream>

int main (){

    const size_t COUNT{10};
    size_t i{0};

    while(i < COUNT)
    {
        std::cout << i << " : I love C++" << std::endl;

        i++;
    }
    std::cout << "Loop done!" << std::endl;

    return 0;
}
*/

#include <iostream>

int main ()
{
    int scores[10];

    /*scores[0] = 20;
    scores[1] = 21;
    scores[2] = 22;

    for (size_t i{0}; i < 10; ++i)
    {
        std::cout << "scores [" << i << "] : " << scores[i] << std::endl;
    }
    */

   /* 
   for (size_t i{0}; i < 10; ++i)
    {
        scores[i] = i * 10;
    }

    for (size_t i{0}; i < 10; ++i)
    {
        std::cout << "scores [" << i << "] : " << scores[i] << std::endl;
    }
    */

   /*
   double salaries[5] {12.7, 7.5, 13.2, 8.1, 9.3};

   for (size_t i{0}; i < 5; ++i)
    {
        std::cout << "salary [" << i << "] : " << salaries[i] << std::endl;
    }
    */

   int class_sizes[] {10,12,15,11,18,17,23,56};

    //RANGE BASED FOR LOOP, READS/OUTPUT THE ELEMENTS OF THE ARRAY 
   for (auto value : class_sizes)
   {
    std::cout << "value : " << value << std::endl;
   }
    
    return 0;
    
}