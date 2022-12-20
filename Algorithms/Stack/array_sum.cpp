#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    // Initialize the array and its size
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create a hash map to store the sums
    unordered_map<int, pair<int, int>> sum_map;

    // Traverse the array and store the sums in the hash map
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Calculate the sum
            int sum = arr[i] + arr[j];
            // Check if the sum is already present in the map
            if (sum_map.find(sum) == sum_map.end())
            {
                // If not, store the sum and the indices in the map
                sum_map[sum] = {i, j};
            }
            else
            {
                // If the sum is present, we have found a pair of numbers
                // that satisfies the condition a + b = c + d
                pair<int, int> indices = sum_map[sum];
                cout << "Pair found: (" << arr[indices.first] << ", " << arr[indices.second] << ") and (" << arr[i] << ", " << arr[j] << ")" << endl;
            }
        }
    }

    return 0;
}
