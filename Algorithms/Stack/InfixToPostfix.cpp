#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

bool isOperator(char op)
{
    return (op == '+' || op == '-' || op == '*' || op == '/' || op == '(');
}
int FirstPrecedence(char first)
{
    int pre;
    if (first == '+' || first == '-')
    {
        pre = 2;
    }
    if (first == '*' || first == '/')
    {
        pre = 4;
    }
    if (first == '(')
    {
        pre = 0;
    }
    return pre;
}
int SecondPrecedence(char second)
{
    int pre;
    if (second == '+' || second == '-')
    {
        pre = 1;
    }
    if (second == '*' || second == '/')
    {
        pre = 3;
    }
    if (second == '(')
    {
        pre = 100;
    }
    return pre;
}

bool isOperand(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '1' && ch <= '9'));
}
bool HasHigherPrecedence(char first, char second)
{
    return FirstPrecedence(first) > SecondPrecedence(second);
}

string InfixToPostfix(string exp)
{
    int n = exp.size();
    string res;
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (isOperand(exp[i]))
        {
            res += exp[i];
        }
        else if (isOperator(exp[i]))
        {
            if (st.empty() || !HasHigherPrecedence(st.top(), exp[i]))
            {
                st.push(exp[i]);
            }
            else
            {
                while (!st.empty() && HasHigherPrecedence(st.top(), exp[i]))
                {
                    res += st.top();
                    st.pop();
                }
                st.push(exp[i]);
            }
        }
        else if (exp[i] == ')')
        {
            while (st.top() != '(')
            {
                res += st.top();
                st.pop();
                if (st.empty())
                {
                    cout << "Invalid Input!" << endl;
                    return "";
                }
            }
            st.pop(); // Opening bracket popoyed
        }
    }
    while (!st.empty())
    {
        if (st.top() == '(')
        {
            cout << "Invalid Input!" << endl;
            return "";
        }
        res += st.top();
        st.pop();
    }
    return res;
}
string InfixToPrefix(string exp)
{
    reverse(exp.begin(), exp.end());

    // Replace ( with ) and vice versa
    int sz = exp.size();
    for (int i = 0; i < sz; i++)
    {
        if (exp[i] == '(')
        {
            exp[i] = ')';
        }
        else if (exp[i] == ')')
        {
            exp[i] = '(';
        }
    }
    string ans = InfixToPostfix(exp);
    reverse(ans.begin() , ans.end());
    return ans;
}

int main(int argc, char const *argv[])
{
    string exp;
    cout << "Enter Expression: ";
    getline(cin, exp);
    cout << InfixToPostfix(exp) << endl;
     cout << InfixToPrefix(exp);

    return 0;
}
