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

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    root = insert(root, 1);
    root->left = insert(root, 2);
    root->right = insert(root, 3);
    root->left->left = insert(root, 4);
    root->left->right = insert(root, 5);
    root->left->left->right = insert(root, 8);
    root->left->left->right->right = insert(root, 12);
    root->left->right->right = insert(root, 9);
    root->right->left = insert(root, 6);
    root->right->right = insert(root, 7);
    root->right->right->left = insert(root, 10);
    root->right->right->right = insert(root, 11);
    Print(root);
    cout << endl;
    cout << DFS(root);

    return 0;
}
