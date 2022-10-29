#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> rhs;
    rhs.push(3);
    rhs.push(69);
    rhs.push(56);
    rhs.push(420);
    rhs.push(42);
    stack<int> temp, result;
    while (!rhs.empty())
    {
        int min = rhs.top();
        while (!rhs.empty())
        {
            if (rhs.top() < min)
            {
                min = rhs.top();
            }
            temp.push(rhs.top());
            rhs.pop();
        }
        while (!temp.empty())
        {
            if (temp.top() == min)
            {
                result.push(min);
                temp.pop();
            }
            else
            {
                rhs.push(temp.top());
                temp.pop();
            }
        }
    }
    while (!result.empty())
    {
        cout << result.top() << " ";
        result.pop();
    }
}