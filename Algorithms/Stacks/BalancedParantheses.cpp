#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
using namespace std;

bool CheckIdentical(char first, char second)
{
    if(first == '(' && second == ')')
    {
        return true;
    }
    if(first == '[' && second == ']')
    {
        return true;
    }
    if(first == '{' && second == '}')
    {
        return true;
    }
    return false;
}

bool CheckParantheses(string exp)
{
    int size = exp.size();
    stack<char> st;

    for (int i = 0; i < size; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            st.push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(st.empty() || !CheckIdentical(st.top(), exp[i]))
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }
    return st.empty() ? true : false;
}

int main(int argc, char const *argv[])
{
    string exp;
    cout << "Enter expression: ";
    getline(cin, exp);
    cout << endl << exp << endl;
    cout << CheckParantheses(exp) << endl;

    return 0;
}
