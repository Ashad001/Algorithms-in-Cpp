#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data = 0, Node *left = NULL, Node *right = NULL)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
class BinaryTree
{
public:
    int size = -1;
    Node *BuildTree(vector<int> &arr)
    {
        size++;
        if (arr[size] == -1)
        {
            return NULL;
        }
        Node *newNode = new Node(arr[size]);
        newNode->left = BuildTree(arr);
        newNode->right = BuildTree(arr);
    }
    void PrintPreorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " -> ";
        PrintPreorder(root->left);
        PrintPreorder(root->right);
    }
    void InOrderTraversal(Node *root)
    {
        // Good For Balanced Binary Tree / Sorted BT
        if (root == NULL)
        {
            return;
        }
        InOrderTraversal(root->left);
        cout << root->data << ", ";
        InOrderTraversal(root->right);
    }
    void LevelOrder(Node *root)
    {
        queue<Node *> qewww;
        qewww.push(root);
        qewww.push(NULL);
        while (!qewww.empty())
        {
            Node *curr = qewww.front();
            qewww.pop();
            if (curr == NULL)
            {
                cout << endl;
                if (qewww.empty())
                {
                    break;
                }
                else
                {
                    qewww.push(NULL);
                }
            }
            else
            {
                cout << curr->data << " ";
                if (curr->left != NULL)
                {
                    qewww.push(curr->left);
                }
                if (curr->right != NULL)
                {
                    qewww.push(curr->right);
                }
            }
        }
        cout << endl;
    }
    int CountNodes(Node *root)
    {
        if (root->left == NULL || root->right == NULL)
        {
            return 1;
        }
        return CountNodes(root->left) + CountNodes(root->right) + 1;
    }
    int SumOfNodes(Node *root)
    {
        if (root->left == NULL || root->right == NULL)
        {
            return root->data;
        }
        return SumOfNodes(root->left) + SumOfNodes(root->right) + root->data;
    }
    int GetHeight(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left = GetHeight(root->left);
        int right = GetHeight(root->right);
        return (left > right) ? left + 1 : right + 1;
    }
    int GetDiameter(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftD = GetDiameter(root->left);
        int RightD = GetDiameter(root->right);
        int Height = GetHeight(root->left) + GetHeight(root->right) + 1;

        return max(Height, max(leftD, RightD));
    }
};

int main(int argc, char const *argv[])
{
    BinaryTree tree;
    vector<int> arr = {1, 2, 3, -1, -1, 4, 5, -1, -1, 3, -1, -1, 6, -1, -1};
    Node *root = tree.BuildTree(arr);
    // tree.PrintPreorder(root);
    tree.LevelOrder(root);
    cout << "Total Node: " << tree.CountNodes(root) << endl;
    cout << "Sum Of Nodes: " << tree.SumOfNodes(root) << endl;
    cout << "Hegiht Of Tree: " << tree.GetHeight(root) << endl;
    cout << "Diameter Of Tree: " << tree.GetDiameter(root) << endl;

    return 0;
}
