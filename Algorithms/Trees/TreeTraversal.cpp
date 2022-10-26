#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void allTraversal(Node *root)
{
    vector<int> pre;
    vector<int> post;
    vector<int> in;
    stack<pair<Node *, int>> s;
    s.push(make_pair(root, 1));

    while (!s.empty())
    {
        pair<Node *, int> p = s.top();

        if (p.second == 1)
        {
            s.top().second++;

            pre.push_back(p.first->data);

            if (p.first->left)
            {
                s.push(make_pair(p.first->left, 1));
            }
        }

        else if (p.second == 2)
        {
            s.top().second++;

            in.push_back(p.first->data);

            if (p.first->right)
            {
                s.push(make_pair(
                    p.first->right, 1));
            }
        }

        else
        {
            post.push_back(p.first->data);
            s.pop();
        }
    }

    cout << "Preorder Traversal: ";
    for (int i = 0; i < pre.size(); i++)
    {
        cout << pre[i] << " ";
    }
    cout << "\n";

    cout << "Inorder Traversal: ";

    for (int i = 0; i < in.size(); i++)
    {
        cout << in[i] << " ";
    }
    cout << "\n";

    cout << "Postorder Traversal: ";

    for (int i = 0; i < post.size(); i++)
    {
        cout << post[i] << " ";
    }
    cout << "\n";
}

int main()
{

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    allTraversal(root);

    return 0;
}
