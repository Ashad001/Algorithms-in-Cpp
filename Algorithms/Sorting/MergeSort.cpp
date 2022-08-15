#include <iostream>

void PrintArray(int *arr, int size);
void MergeSort(int *arr, int leftIndex, int rightIndex);

int main()
{
    int array[] = {5, 4, 1, 6, 2};
    int size = sizeof(array) / sizeof(array[0]);
    PrintArray(array, size);

    MergeSort(array, 0, size - 1);
    PrintArray(array, size);

    return 0;
}

void PrintArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

void Merge(int *arr, int leftIndex, int middle, int rightIndex)
{
    // get the sizes of the two auxiliary arrays
    const int subArrSize1 = middle - leftIndex + 1;
    const int subArrSize2 = rightIndex - middle;

    // reserve the memory for the two auxiliary arrays
    int *subArr1 = new int[subArrSize1];
    int *subArr2 = new int[subArrSize2];

    // copy the values of the left side array into the auxiliary array
    int j = 0;
    for (int i = leftIndex; i <= middle; i++)
    {
        subArr1[j++] = arr[i];
    }
    // copy the values of the right side array into the auxiliary array
    int p = 0;
    for (int i = middle + 1; i <= rightIndex; i++)
    {
        subArr2[p++] = arr[i];
    }

    // move the values from the auxiliary arrays to the main array
    j = 0;
    p = 0;
    for (int i = leftIndex; i <= rightIndex; i++)
    {
        // check if both arrays are still being checked
        if (j < subArrSize1 && p < subArrSize2)
        {
            // if so, then check which value is smaller
            if (subArr1[j] < subArr2[p])
            {
                arr[i] = subArr1[j++];
            }
            else
            {
                arr[i] = subArr2[p++];
            }
        }
        // if one array is out of bounds, merge the values from the one, which is not out of bounds
        else if (j < subArrSize1 && p >= subArrSize2)
        {
            arr[i] = subArr1[j++];
        }
        else
        {
            arr[i] = subArr2[p++];
        }
    }

    // free the space on the heap
    delete[] subArr1;
    delete[] subArr2;
}

void MergeSort(int *arr, int leftIndex, int rightIndex)
{
    // check if the array has been divided until only one value is left
    if (leftIndex >= rightIndex)
        return;

    int middle = (leftIndex + rightIndex) / 2; // get the middle of the array

    // divide the left and right side array again
    MergeSort(arr, leftIndex, middle);
    MergeSort(arr, middle + 1, rightIndex);
    // after we divided the array, merge the parts together
    Merge(arr, leftIndex, middle, rightIndex);
}