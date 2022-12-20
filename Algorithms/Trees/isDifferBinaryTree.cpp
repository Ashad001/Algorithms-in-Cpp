#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int key;
    Node *left, *right;
    Node(int key)
    {
        this->key = key;
        this->left = this->right = NULL;
    }
};

class BST
{
public:
    Node *root;
    BST(int key)
    {
        this->root = new Node(key);
    }
    void Add(int key)
    {
        Node *temp = root;
        while (temp != NULL)
        {
            if (key < temp->key)
            {
                if (temp->left == NULL)
                {
                    temp->left = new Node(key);
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = new Node(key);
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
    int GetHeight(Node *temp)
    {
        if (temp != NULL)
        {
            int a = GetHeight(temp->left), b = GetHeight(temp->right);
            return (a > b ? a : b) + 1;
        }
        return -1;
    }
    void InOrderPrint(Node *temp)
    {
        if (temp != NULL)
        {
            InOrderPrint(temp->left);
            cout << temp->key << " ";
            InOrderPrint(temp->right);
        }
        return;
    }
    bool isDifferenceBinaryTree(Node *temp)
    {
        if (temp != NULL)
        {
            if (temp->left == NULL && temp->right == NULL)
            {
                return true;
            }
            int sumOfLeft = getSumOfAllNodes(temp->left);
            int sumOfRight = getSumOfAllNodes(temp->right);
            if (temp->key == sumOfLeft - sumOfRight)
            {
                return true && isDifferenceBinaryTree(temp->left) && isDifferenceBinaryTree(temp->right);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    int getSumOfAllNodes(Node *temp)
    {
        if (temp != NULL)
        {
            return temp->key + getSumOfAllNodes(temp->left) + getSumOfAllNodes(temp->right);
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    // Example 01
    BST B(18);
    B.root->left = new Node(10);
    B.root->right = new Node(5);
    B.root->left->left = new Node(20);
    B.root->left->right = new Node(10);
    B.root->right->left = new Node(11);
    B.root->right->right = new Node(6);
    cout << (B.isDifferenceBinaryTree(B.root) == true ? "Yes" : "No");

    // Example 02
    // BST B(-22);
    // B.root->right = new Node(5);
    // B.root->right->left = new Node(11);
    // B.root->right->right = new Node(6);
    // cout << (B.isDifferenceBinaryTree(B.root) == true ? "Yes" : "No");

    // Example 03
    // BST B(40);
    // B.root->left = new Node(21);
    // B.root->left->left = new Node(20);
    // B.root->left->right = new Node(-1);
    // cout << (B.isDifferenceBinaryTree(B.root) == true ? "Yes" : "No");
    return 0;
}