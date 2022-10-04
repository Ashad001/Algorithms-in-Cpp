//CONTRIBUTED BY ARYAN GUPTA



#include<iostream>
#include<algorithm>
using namespace std;
 
//method to swap two numbers.

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void sortInWave(int arr[], int n)
{
    sort(arr, arr+n);

  for (int i=0; i<n-1; i += 2)
        swap(&arr[i], &arr[i+1]);
}
 
int main()
{
    int arr[] = {10, 90, 49, 2, 1, 5, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortInWave(arr, n);
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
    return 0;
}
