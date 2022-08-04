#include <iostream>
using namespace std;

float SqureRoot(int n)
{
    int start = 0;
    int end = n;
    float ans = 1;
    while(start < end)
    {
        int mid = start + (end - start) / 2;
        if(mid * mid == n)
        {
            return (float)mid;
        }
        else if(mid * mid < n)
            start = mid + 1;
        else
            end = mid - 1;
    }
    ans = end;
    while(ans * ans <= n)
    {
        ans += 0.001;
    }
    
    return ans;   
}


int main(int argc, char const *argv[])
{
    cout << SqureRoot(40) << endl;

    
    return 0;
}
