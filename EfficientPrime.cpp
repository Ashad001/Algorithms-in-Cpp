#include <iostream>
#include <math.h>
using namespace std;

void PrimeTillN(const int n, bool *arr)
{
    for(int i = 2; i < sqrt(n); i++)
    {
        if(!arr[i])
        {
            for(int j = i * i; j < n; j+=i)
            {
                arr[j] = true;
            }
        }
    }
    for(int i = 2 ; i < n; i++)
    {
        if(!arr[i])
        {
            cout << i << " is a prime number" << endl;
        }
    }
}

void Prime(int n)
{
    for(int i = 2; i < sqrt(n); i++)
    {
        if(n % i == 0)
        {
            cout << "Not A Prime Number" << endl;
            return;
        }
    }
    cout << "Prime Number" << endl;
}

int main(int argc, char const *argv[])
{
    const int n = 50;
    bool arr[n + 1];

    PrimeTillN(n, arr);
    
    return 0;
}
