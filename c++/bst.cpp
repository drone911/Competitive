#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data)
    {
        left = NULL;
        right = NULL;
    }
};
class BST
{
    Node *root;
    int n;
    void _inorder(Node *root)
    {
        if (root)
        {
            _inorder(root->left);
            cout << root->data << " ";
            _inorder(root->right);
        }
    }
    void _insert(Node *node, Node *toInsert)
    {
        if (node->data < toInsert->data)
        {
            if (node->right)
            {
                _insert(node->right, toInsert);
            }
            else
            {
                node->right = toInsert;
            }
        }
        else
        {
            if (node->left)
            {
                _insert(node->left, toInsert);
            }
            else
            {
                node->left = toInsert;
            }
        }
    }

public:
    BST(int data)
    {
        root = new Node(data);
        n = 1;
    }

    void insert(int data)
    {
        Node *toInsert = new Node(data);
        _insert(root, toInsert);
        n++;
    }
    void inorder()
    {
        _inorder(root);
        cout << endl;
    }
    bool find(int data)
    {
        Node *temp = root;
        while (true)
        {
            if (temp->data == data)
            {
                return true;
            }
            if (temp->data > data)
            {
                if (temp->left)
                {
                    temp = temp->left;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (temp->right)
                {
                    temp = temp->right;
                }
                else
                {
                    break;
                }
            }
        }
        return false;
    }
};
int main()
{
    BST bst(5);
    bst.insert(6);
    bst.insert(2);
    bst.insert(3);
    bst.insert(9);
    bst.insert(10);
    bst.inorder();
    cout << bst.find(2) << " " << bst.find(11);
}