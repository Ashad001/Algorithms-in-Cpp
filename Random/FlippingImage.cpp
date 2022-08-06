#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> FlipImage(vector<vector<int>> &image)
{
    for(auto row : image) 
    {
        for(int j = 0; j < (image[0].size() + 1) / 2; j++)
        {
            int temp = row[j]  ^ 1;
            row[j] = row[image[0].size() - j - 1] ^ 1;
            row[image[0].size() - j - 1] = temp;
        }
    }
   
    return image;
};
int main(int argc, char const *argv[])
{
    vector<vector<int>> input = {
        {1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
    vector<vector<int>> ans = FlipImage(input);
    cout << int(1 ^ 1) << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            cout << ans[i][j] << " , ";
        }
        cout << endl;
    }

    return 0;
}
