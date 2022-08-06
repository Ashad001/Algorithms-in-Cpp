#include <iostream>
using namespace std;

void Print(int num)
{
    cout << num << endl;
}
int main(int argc, char const *argv[])
{
    int n = -1;
    if(n != 5)
    {
        Print(n + 1);
    }
    
    return 0;
}
