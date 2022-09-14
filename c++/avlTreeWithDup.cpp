#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
    int count;
};
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->right = NULL;
    node->left = NULL;
    node->height = 1;
    node->count = 1;
    return node;
}
int height(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return node->height;
    }
}
int getBalance(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return height(node->left) - height(node->right);
    }
}
Node *leftRotate(Node *root)
{
    Node *newRoot = root->right;
    Node *subTree = newRoot->left;

    root->right = subTree;
    newRoot->left = root;

    newRoot->height = max(height(newRoot->left), height(newRoot->right))+1;
    root->height = max(height(root->left), height(root->right))+1;

    return newRoot;
}
Node *rightRotate(Node *root)
{
    Node *newRoot = root->left;
    Node *subTree = newRoot->right;

    root->left = subTree;
    newRoot->right = root;

    newRoot->height = max(height(newRoot->left), height(newRoot->right));
    root->height = max(height(root->left), height(root->right));

    return newRoot;
}
Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return newNode(data);
    }
    if (root->data == data)
    {
        root->count++;
        return root;
    }
    if (root->data < data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        root->left = insert(root->left, data);
    }
    root->height = max(height(root->left), height(root->right))+1;

    int balance = getBalance(root);
    //LR
    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    //LL
    if (balance > 1 && data < root->left->data)
    {
        return rightRotate(root);
    }
    //RR
    if (balance < -1 && data > root->right->data)
    {
        return leftRotate(root);
    }
    //RL
    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}

void printLevelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    int num = 0;
    int level = 0;
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        
        cout << curr->data<<" ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
    cout << endl;
}
int main()
{
    Node *root = NULL;
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 0);
    root = insert(root, -1);
    
    printLevelOrder(root);
    return 0;
}