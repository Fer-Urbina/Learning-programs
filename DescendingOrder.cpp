#include <iostream>

int main ()
{
    int arr[] = {5, 2, 8, 7, 1};
    int temp = 0;
    int length;

    length = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Elements of original array: \n";
    for (int i = 0; i < length; i++)
    {
        std::cout << arr[i];
    }

    //Sort the array in descending order
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    std::cout << "\nElements of array sorted in descending order: \n";
    for (int i = 0; i < length; i++)
    {
        std::cout << arr[i];
    }
    return 0;
}

