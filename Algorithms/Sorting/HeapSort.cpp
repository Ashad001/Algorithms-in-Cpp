#include <iostream>
using namespace std;
void heapify(int arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
<<<<<<< HEAD
    if (largest != i)
    {
=======
    if (largest != i) {
>>>>>>> 4f492d9ad04ff8a3d4eac73ae67f5d6969be98f9
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
<<<<<<< HEAD
    for (int i = N - 1; i > 0; i--)
    {
=======
    for (int i = N - 1; i > 0; i--) {
>>>>>>> 4f492d9ad04ff8a3d4eac73ae67f5d6969be98f9
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
<<<<<<< HEAD
    int arr[] = {12, 11, 13, 5, 6, 7};
=======
    int arr[] = { 12, 11, 13, 5, 6, 7 };
>>>>>>> 4f492d9ad04ff8a3d4eac73ae67f5d6969be98f9
    int N = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, N);
    cout << "Sorted array is \n";
    printArray(arr, N);
<<<<<<< HEAD
}
=======
}
>>>>>>> 4f492d9ad04ff8a3d4eac73ae67f5d6969be98f9
