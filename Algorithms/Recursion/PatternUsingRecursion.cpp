#include <iostream>
using namespace std;

void Pat1(int r, int c)
{
    if (r == 0)
        return;
    if (r == c)
    {
        cout << endl;
        Pat1(r - 1, 0);
    }
    else
    {
        cout << "* ";
        Pat1(r, c + 1);
    }
};

int main(int argc, char const *argv[])
{
    Pat1(5, 0);
    return 0;
}
