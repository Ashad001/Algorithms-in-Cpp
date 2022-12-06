#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data = 0)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

Node *Insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = Insert(root->right, data);
    }
    return root;
}
void PrintTree(Node *root, int space = 0)
{
    static int count = 10;
    if (root == NULL)
    {
        return;
    }
    space += count;
    PrintTree(root->right, space);
    cout << endl;
    for (int i = count; i < space; i++)
    {
        cout << " ";
    }
    cout << root->data << endl;
    PrintTree(root->left, space);
}
void PrintInorder(Node *root) // Sorted Printing Since it is a BST
{
    if (root == NULL)
    {
        return;
    }
    PrintInorder(root->left);
    cout << root->data << ", ";
    PrintInorder(root->right);
}
void PrintPreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ", ";
    PrintInorder(root->left);
    PrintInorder(root->right);
}
void PrintPostOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PrintPostOrder(root->left);
    PrintPostOrder(root->right);
    cout << root->data << ", ";
}
bool Search(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }
    else if (data < root->data)
    {
        return Search(root->left, data);
    }
    else
    {
        return Search(root->right, data);
    }
}

int SumOfNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return SumOfNodes(root->left) + SumOfNodes(root->right) + root->data;
}
int HeightOfATree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = HeightOfATree(root->left);
    int right = HeightOfATree(root->right);
    return (left > right) ? left + 1 : right + 1;
}
int DiameterOfATree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int Height = HeightOfATree(root->left) + HeightOfATree(root->right);
    int leftD = DiameterOfATree(root->left);
    int RightD = DiameterOfATree(root->right);
    return max(Height, max(leftD, RightD));
}

Node *MinInBST(Node *root)
{
    if (root == NULL)
    {
        cerr << "Tree is empty!";
        return NULL;
    }
    if (root->left == NULL)
    {
        return root;
    }
    return MinInBST(root->left);
}
Node *MaxInBST(Node *root)
{
    if (root == NULL)
    {
        cerr << "Tree is empty!";
        return NULL;
    }
    if (root->right == NULL)
        return root;
    return MinInBST(root->right);
}
void LevelOrderTraversal(Node *root) // Depth First
{
    if (root == NULL)
    {
        cerr << "Tree is empty!";
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        if (curr != NULL)
            cout << curr->data << " -> ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
        q.pop();
    }
}

bool DepthFirstSearch(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        if (curr->data == data)
        {
            return true;
        }
        else if (curr->left != NULL && data < curr->data)
        {
            q.push(curr->left);
        }
        else if (curr->right != NULL && data > curr->data)
        {
            q.push(curr->right);
        }
        q.pop();
    }
    return false;
}
Node *Delete(Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = Delete(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            root = NULL;
        }
        else if (root->left == NULL)
        {
            root = root->right;
        }
        else if (root->right == NULL)
        {
            root = root->left;
        }
        else
        {
            Node *temp = MinInBST(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, root->data);
        }
    }
}
int LevelOfNode(Node *root, int val)
{
    if (root == NULL)
        return -1;

    queue<Node *> q;
    q.push(root);
    int count = -1;
    bool check = false;
    while (!q.empty())
    {
        Node *curr = q.front();
        count++;
        if (curr->data == val)
        {
            check = true;
            break;
        }
        else if (curr->left != NULL && val < curr->data)
        {
            q.push(curr->left);
        }
        else if (curr->right != NULL && val > curr->data)
        {
            q.push(curr->right);
        }
        q.pop();
    }
    return (check == true) ? count : -1;
}
int CountNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return CountNodes(root->right) + CountNodes(root->left) + 1;
}

int CountRightNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int k = (root->right) ? 1 : 0;
    return CountRightNodes(root->left) + CountRightNodes(root->right) + k;
}

int CountLeaves(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = (root->left == NULL && root->right == NULL) ? 1 : 0;
    return l + CountLeaves(root->left) + CountLeaves(root->right);
}

int main(int argc, char const *argv[])
{
    // Node *root = NULL;
    // root = Insert(root, 10);
    // root = Insert(root, 20);
    // root = Insert(root, 2);
    // root = Insert(root, 5);
    // root = Insert(root, -2);
    // root = Insert(root, 0);
    // root = Insert(root, 40);
    // root = Insert(root, 25);
    // PrintTree(root);
    // cout << HeightOfATree(root) << endl;
    // // cout << CountNodes(root) << endl;
    // // LevelOrderTraversal(root);
    // cout << endl;
    vector<vector<string>> s = {
        {"ashad", "ayehs", "faheel"},
        {"fgf"},
        {"hjgsfd"}};
    cout << s.at(0).at(1) << endl;
    // // cout << DepthFirstSearch(root, -2);
    // cout << LevelOfNode(root, 25);
    // PrintInorder(root);
    // cout << endl;
    // PrintPreOrder(root);
    // cout << endl;
    // cout << DiameterOfATree(root) << endl;
    // PrintPostOrder(root);
    // cout << endl;
    // PrintInorder(root);
    // cout << endl;
    // PrintPreOrder(root);
    // cout << endl;
    // cout << SumOfNodes(root) << endl;
    // cout << HeightOfATree(root) << endl;
    // cout << "Enter number to be searched: ";
    // int s;
    // cin  >> s;
    // if(Search(root, s))
    // {
    //     cout << "FOUND!" << endl;
    // }
    // else
    // {
    //     cout << "Not Found!" << endl;
    // }
    // cout << MinInBST(root) << endl;
    // cout << MaxInBST(root) << endl;
    // LevelOrderTraversal(root);
    // cout << endl;
    // if (DepthFirstSearch(root, 25))
    // {
    //     cout << "Found!" << endl;
    // }
    // else
    // {
    //     cout << "Not Found!" << endl;
    // }

    // PrintInorder(root);
    // cout << endl;
    // Delete(root, 2);
    // PrintInorder(root);
    // cout << endl;

    return 0;
}
