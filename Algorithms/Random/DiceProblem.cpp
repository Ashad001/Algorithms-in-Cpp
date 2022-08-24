#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void Dice(string ans, int num, int face)
{

    if (num == 0)
    {
        cout << ans << endl;
        return;
    }
    else
    {
        for (int i = 1; i <= face && i <= num; i++)
        {
            Dice(ans + to_string(i), num - i, face);
        }
    }
};

vector<string> DiceRet(string ans, int num, int tar, int n, int k)
{
    if (num == 0)
    {
        vector<string> list;
        if (ans.size() == n)
            list.push_back(ans);
        return list;
    }
    vector<string> PosAns;
    for (int i = 1; i <= k & i <= num; i++)
    {
        vector<string> list;
        list = DiceRet(ans + to_string(i), num - i, tar, n, k);
        PosAns.insert(PosAns.end(), list.begin(), list.end());
    }
    return PosAns;
};

int DiceRetCount(string ans, int num, int n, int k)
{
    if (num == 0)
    {
        if (ans.size() == n)
        {
            return 1;
        }
        return 0;
    }
    int count = 0;
    for (int i = 1; i <= k & i <= num; i++)
    {
        count = count + DiceRetCount(ans + to_string(i), num - i, n, k);
    }
    return int(count % int(pow(10.0,9.0) + 7));

};

int main(int argc, char const *argv[])
{
    // Dice("", 7, 22);
    int count = DiceRetCount("", 500, 30, 30);
    // for(auto a : ans)
    cout << count << endl;

    return 0;
}
