#include <iostream>

int find_minimum(int array[], int length)
{
    int min;

    min = array[0];

    for (int i = 1; i < 9; i++) {
        std::cout << "Checking array [" << i << "] = " << array[i] << "\n"; 
        if (array[i] < min){
            min = array[i];
            std::cout << "New min found " << min << std::endl;
        }
    }
    return min;
}

int main()
{
    int array1[] = {5,6,9,7,3,8,4,10,2};
    int array2[] = {5,6,8,4,3,1,8,9};
    
    int min1 = find_minimum(array1, 9);
    int min2 = find_minimum(array2, 8);

    std::cout << "Minimum number found: " << min1 << std::endl;
    std::cout << "Minimum number found: " << min2 << std::endl;

    return 0;
}