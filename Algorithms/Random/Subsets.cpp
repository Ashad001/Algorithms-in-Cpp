#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

list<list<int>> Subset(list<int> &arr)
{
    list<list<int>> outer;
    outer.push_back(list<int>());
    for (auto num : arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            list<int> internal;
            internal.splice(internal.end(), outer.front());
            internal.push_back(num);
            outer.push_back(internal);
        }
    }
    return outer;
}

int main(int argc, char const *argv[])
{
    list<int> arr = {1, 2, 3, 4};
    for (auto num : arr)
        cout << num << endl;
    list<list<int>> ans = Subset(arr);

    for (auto i1 = arr.begin(); i1 != arr.end(); i1++)
    {
        list<int> &list2 = &i1;
        for (auto j = list2.begin(); j != list2.end(); j++)
        {
            cout << *j << " ";
        }
        cout << endl;
    }

    return 0;
}
