/*
Question # 02: Points: 10
Stack:
These are pancakes, a gaping hole in the "eat a healthy breakfast" story that Mom and Dad like to
tell us. I'm not good enough at baking to make a perfect stack of pancakes all the same size, like the
picture. Mine are more likely to look like the bottom stack. Still, they are yummy.
I like the order and symmetry of having my pancakes in order by size, largest on bottom. That way,
the syrup and extra butter will run down and sweeten the whole stack! But my mom won't let me
rearrange the pancakes by hand.

They, however, do let me use a spatula, aka "the flipper". I am able to slip the spatula under any
pancake and flip over the entire stack on top of the spatula. That took a lot of practice! I also have
to rearrange the pancakes "in place" -- no extra plate allowed. So I do. (That took even more
practice!)
But: how can I do this quickly, before my mom tells me to stop playing with my food? This is your
task: help me put my pancakes in order.
You have a stack of n pancakes of all different sizes, in no particular order. You are able to slip a
spatula under any pancake and flip over the whole stack that is on the spatula. You would like to
arrange my pancakes in order by size, largest on bottom.
Let's proceed in two steps:
1. Just think for a minute about how you would do this.
2. Write down your code. How many times must you flip the pancakes?
Research paper: https://core.ac.uk/download/pdf/81955056.pdf
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void StackSortUtil(stack<int> &s, int top)
{
    if (s.empty())
    {
        s.push(top);
        return;
    }
    int nTop = s.top();
    if (nTop < top)
    {
        int i = top;
        top = nTop;
        nTop = i;
    }

    s.pop();
    StackSortUtil(s, nTop);
    s.push(top);
}

void stackSort(stack<int> &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        int top = s.top();
        s.pop();
        StackSortUtil(s, top);
    }
}
void PrintStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " , ";
        s.pop();
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    stack<int> st;
    st.push(2);
    st.push(5);
    st.push(1);
    st.push(4);
    st.push(3);
    st.push(7);
    st.push(6);
    PrintStack(st);
    stackSort(st);
    PrintStack(st);
    return 0;
}
