#include <iostream>
#include <vector>
#include <string>
using namespace std;
string Substr(string str, int st, int end)
{
    string ans;
    for (int i = st; i < end; i++)
        ans += str[i];
    return ans;
}
void letterCombinations(string ans, string str)
{
    if (str.empty())
    {
        cout << ans << endl;
        return;
    }
    else
    {
        int digit = str[0] - '0';
        for (auto i = (digit - 2) * 3; i < ((digit - 1) * 3); i++)
        {
            char ch = char('a' + i);
            letterCombinations(ans + ch, str.substr(1));
        }
    }
};

int main(int argc, char const *argv[])
{
    letterCombinations("", "23");

    return 0;
}
