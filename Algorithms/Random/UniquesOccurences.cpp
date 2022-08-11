#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool Unique(vector<int> &arr)
{
    map<int, int> unq;

    for(int i = 0; i < arr.size(); i++)
    { 
        int count = 0;
        if(unq.count(arr[i]) != 0)
        {
            unq[arr[i]] = ++count;
        }        
        else
        {
            unq.insert(pair<int,int>(arr[i], count));
        }
    }
    int s = 0;
    for(auto pair = unq.begin(); pair != unq.end(); pair++)
    {
        if(pair->second >= 0)
        {
            s++;
        }
    }
 
    cout << s << unq.size() << endl;
    return s == unq.size() ? true : false;
};

int main(int argc, char const *argv[])
{
    vector<int> arr = {1,1,2,2,2,3,3,3,3};

    bool ans = Unique(arr);
    cout << ans;

    
    return 0;
}
