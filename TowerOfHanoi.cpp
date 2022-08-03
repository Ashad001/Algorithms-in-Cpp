#include <iostream>
#include <vector>
using namespace std;

void TOH(int n, char A, char B, char C)
{
    if (n == 1)
    {
        cout << "Move " << A  <<" to " << C << endl;
        return;
    }
    TOH(n - 1, A, C, B);
    TOH(1, A, B, C);
    TOH(n - 1, B,A,C);
}

int main(int argc, char const *argv[])
{
    TOH(2, 'A','B','C');

    return 0;
}
