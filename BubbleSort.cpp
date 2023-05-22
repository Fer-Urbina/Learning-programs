// We make usage of the Bubble Sort Algorithm
// This is a simple program to sort the elements of an array in ascending order

#include <iostream>

void bubble_sort(int array[], int length)
{
    //Sort the array in descending || ascending order
    for (int i = 0; i < length; i++)
    {
        int temp = 0;

        for (int j = i + 1; j < length; j++)
        {
            if (array[i] < array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main ()
{
    int arr[] = {5, 2, 8, 7, 1};
    int length;

    length = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Elements of original array: \n";
    for (int i = 0; i < length; i++)
    {
        std::cout << arr[i] << " ";
    }

    bubble_sort(arr, length);

    std::cout << "\nElements of array sorted in descending order: \n";
    for (int i = 0; i < length; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}

