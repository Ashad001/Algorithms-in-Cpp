#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};
void Print(Node *root)
{
    if (root != NULL)
    {
        Print(root->left);
        cout << root->val << ", ";
        Print(root->right);
    }
}
Node *insert(Node *root, int val)
{
    root = new Node(val);
    return root;
}

int DFS(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return 0;
    }
    return (min(DFS(root->left), DFS(root->right)) + 1);
}

int ToDepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int sum = 0;
    if (root->left && root->right)
        sum = root->left->val - root->right->val;
    return sum + ToDepth(root->left) + ToDepth(root->right);
}
int SumNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->val + (SumNodes(root->left)) + SumNodes(root->right);
}

bool isDifferTree(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->val << endl;
        return true;
    }
    int left = SumNodes(root->left);
    int right = SumNodes(root->right);
    if (root->val == left - right)
    {
        return true && isDifferTree(root->left) && isDifferTree(root->right);
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    root = insert(root, 18);
    root->right = insert(root, 5);
    root->left = insert(root, 10);
    root->left->left = insert(root, 20);
    root->left->right = insert(root, 10);
    root->right->right = insert(root, 6);
    root->right->left = insert(root, 11);

    Print(root);
    cout << endl;
    cout << isDifferTree(root);
    cout << endl;
    Print(root);

    return 0;
}
