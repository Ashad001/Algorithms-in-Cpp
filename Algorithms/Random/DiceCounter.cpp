#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int Sum(string str)
{
    int i = 0;
    int sum = 0;
    while (str[i] != '\0')
    {
        sum += (str[i] - '0');
        i++;
    }
    return sum;
}
int Dice(string ans, int num, int target, int count, int n, int k)
{
    if (num == 0)
    {
        cout << ans << endl;
        if (ans.size() == n && Sum(ans) == target)
        {
            count++;
        }
        return count;
    }
    else
    {
        for (int i = 1; i <= k & i <= num; i++)
        {
            return Dice(ans + to_string(i), num - i, target, count, n, k);
        }
    }
    // return count;
}
int numRollsToTarget(int n, int k, int target)
{
    return Dice("", target, target, 0, n, k);
}

int main(int argc, char const *argv[])
{
    int ans = numRollsToTarget(2, 6, 7);
    cout << ans;

    return 0;
}