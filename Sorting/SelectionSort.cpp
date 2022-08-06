#include <iostream>
#include <vector>
using namespace std;

int Min(vector<int> &arr, int start, int end);
void SelectionSort(vector<int> &arr);


int main(int argc, char const *argv[])
{
    vector<int> vec = {5 ,4 ,1 ,6 ,2};
    SelectionSort(vec);
    for (auto numbers : vec)
    {
        cout << numbers << " ";
    }

    return 0;
}

int Min(vector<int> &vec, int start, int end) // Takes a particular range and finds the minimum within that range in the vector
{ 
    // Set the minimum value to the maximum number
    int min = INT_MAX; 
    int index = 0;
    for (int i = start; i < end; i++)
    {
        // Check every element if it is less then the previous min value update the min value!
        if (vec[i] < min)
        {
            min = vec[i];
            index = i;
        }
    }
    return index;
}

void SelectionSort(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        // Checks the minimum number in a vector within i and vectors's last element
        // And replaces it with the i(th) element.
        int first = i;
        int min = Min(vec, first, vec.size());
        int temp = vec[first];
        vec[first] = vec[min];
        vec[min] = temp;
    }
}

