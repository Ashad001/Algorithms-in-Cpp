#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <list>
#include <algorithm>

using namespace std;

bool f(int x, int y)
{
    return x > y;
}
void PrintVector(vector<int> &arr)
{
    cout << endl
         << "[";
    for (auto num : arr)
        cout << num << ", ";
    cout << "]";
}
void Vector()
{
    
    vector<int> arr = {4, 3, 25, 6, 55, 2};
    arr.front() = 24;
    sort(arr.begin(), arr.end());
    PrintVector(arr);
    bool present = binary_search(arr.begin(), arr.end(), 56);  // false
    bool present2 = binary_search(arr.begin(), arr.end(), 56); // true
    arr.push_back(134);
    arr.push_back(134);
    arr.push_back(134);
    arr.push_back(153);
    PrintVector(arr);
    vector<int>::iterator it = lower_bound(arr.begin(), arr.end(), 134); // >= Will give iterator to first 134 occured
    auto it2 = upper_bound(arr.begin(), arr.end(), 134);                 // > Will give iterator to number which occured after 134
    cout << endl
         << *it << " " << *it2 << endl; // contents of the iterator
    cout << it2 - it << endl;           // basic artihemetic can be applied can be of use : count the number of element!!!
    // To print arr in sorted reverse order
    // sort(arr.begin(), arr.end(), f); // the third argument it needs is just a comparator function
    // You dont need to define a function just lie above instead you can do
    sort(arr.begin(), arr.end(), greater<int>());
    PrintVector(arr);
}

int main(int argc, char const *argv[])
{
    
    
    Vector();
    return 0;
}
