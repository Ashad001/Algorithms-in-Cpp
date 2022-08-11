#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    map<int, int> counts;
    counts.insert(pair<int, int>(1, 0));
    counts.insert(pair<int, int>(2, 1));
    counts.insert(pair<int, int>(3, 2));
    counts.insert(pair<int, int>(4, 3));
    counts.erase(1);
    for (auto pair : counts)
    {
        if (pair.first <= 4)
            pair.second++;
        cout << pair.first << " - " << pair.second << endl;
    }

    return 0;
}
