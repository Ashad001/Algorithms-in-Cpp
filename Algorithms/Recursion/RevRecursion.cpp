#include <iostream>
#include <math.h>
using namespace std;

int Rev(int n)
{
    // cout << (int)log10(n);
    static long base = pow(10 , (int)log10(n) + 1);
    if(n < 10)
        return n;
    base /= 10;
    return (n % 10) * base + Rev(n / 10);
}


int main(int argc, char const *argv[])
{   
    cout << Rev(12345);

    
    return 0;
}
