#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

void Subset(string ans, string str)
{
    if (str.empty())
    {
        cout << ans << endl;
        return;
    }
    Subset(ans + str[0], str.substr(1));
    Subset(ans, str.substr(1));
};
vector<string> ReturnSubset(string ans, string str)
{
    if (str.empty())
    {
        vector<string> list;
        list.push_back(ans);
        return list;
    }
    vector<string> left = ReturnSubset(ans + str[0], str.substr(1));
    vector<string> right = ReturnSubset(ans, str.substr(1));

    left.insert(left.end(), right.begin(), right.end());
    return left;
}

int main(int argc, char const *argv[])
{
    string str = "abcd";
    vector<string> ans = ReturnSubset("", str);
    for (auto sets : ans)
    {
        cout << sets << endl;
    }

    return 0;
}
