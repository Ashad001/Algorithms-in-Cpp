#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// Input: “assassin”
// nissassa
// Output: “in“
// Input: “pacific ocean”
// Output: “pcf oen“
// Input: “an assassin sins”
// Output: “an“

string removePairs(string str)
{
    stack<char> st1;
    stack<char> st2;
    int s = str.size();
    for (int i = 0; i < s; i++)
    {
        st1.push(str[i]);
    }
    char stTop = '\0';
    while (!st1.empty())
    {
        int c = st1.top();
        st1.pop();
        while (!st1.empty() && st1.top() != c)
        {
            st2.push(st1.top());
            st1.pop();
        }
        bool match = false;
        if (!st1.empty())
        {
            match = true;
            st1.pop();
        }
        while (!st2.empty() && st2.top() != stTop)
        {
            st1.push(st2.top());
            st2.pop();
        }
        if (!match)
        {
            st2.push(c);
            stTop = c;
        }
    }
    string res;
    while (!st2.empty())
    {
        res.push_back(st2.top());
        st2.pop();
    }
    return res;
}

int main(int argc, char const *argv[])
{
    cout << removePairs("assassins");
    return 0;
}
