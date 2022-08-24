#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int Floor(vector<int> &arr, int target);
void Sort(vector<int> &arr);

int minMovesToSeat(vector<int> &seats, vector<int> &students)
{
    int count = 0;
    Sort(seats);
    int flr[students.size()] = {};
    for (int i = 0; i < students.size(); i++)
    {
        flr[i] = Floor(seats, students[i]);
        for(int j = 0; j < i; j++)
        {
            if(seats[flr[i]] == seats[flr[j]])
            {
                flr[i]++;
            }
        }
        cout << flr[i] << ", ";
        count += abs(students[i] - seats[flr[i]]);
    }
    cout << endl;
    return count;
}
void Sort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else
            {
                break;
            }
        }
    }
}
int Floor(vector<int> &arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    if (start < arr.size())
        return start;
    else
        return end;
}
int main(int argc, char const *argv[])
{
    vector<int> seats = {2,2,6,6};
    vector<int> students = {1, 3, 2, 6};
    cout << minMovesToSeat(seats, students) << endl;

    return 0;
}
