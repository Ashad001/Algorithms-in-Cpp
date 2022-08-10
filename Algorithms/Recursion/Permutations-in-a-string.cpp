#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;

string Substr(string str, int start, int end)
{
    string ans;
    for (int i = start; i < end; i++)
    {
        ans += str[i];
    }
    return ans;
}

void Permutation(string ans, string str)
{
    if (str.empty())
    {
        cout << ans << " , ";
        return;
    }

    char ch = str[0];
    for (int i = 0; i <= ans.size(); i++)
    {
        string first = Substr(ans, 0, i);
        string second = Substr(ans, i, ans.size());
        Permutation(first + ch + second, str.substr(1));
    }
}

int main(int argc, char const *argv[])
{
    string str = "cba";
    Permutation("", str);

    return 0;
}
