#include <iostream>
#include <vector>
using namespace std;

int CountWays(int rows, int columns)
{
    if(rows <= 1 || columns <= 1)   
        return 1;
    return CountWays(rows - 1, columns) + CountWays(rows, columns - 1);
}


int main(int argc, char const *argv[])
{
    int ans = CountWays(4,4);
    cout << ans << endl;
    
    return 0;
}
