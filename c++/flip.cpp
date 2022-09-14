#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node* parent;
};
Node *newNode(int data, Node* parent)
{
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = parent;
    return node;
}
void printLevelOrder(Node *root)
{
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty()) {
        Node* curr = Q.front();
        Q.pop();
        cout<<curr->data<<" ";
        if(curr->left) {
            Q.push(curr->left);
        }
        if(curr->right) {
            Q.push(curr->right);
        }
    }
}
Node* findMostLeft(Node* root) {
    if(root->left==NULL) {
        return root;
    }else{
        return findMostLeft(root->left);
    }
}

Node* flipBinaryTree(Node* root) {
    if(root==NULL) {
        return root;
    }
    if(root->left == NULL && root->right == NULL) {
        return root;
    }
    Node* flipped = flipBinaryTree(root->left);
    
    root->left->left = root->right; 
    root->left->right = root; 
    root->left = root->right = NULL; 
    return flipper;
}
int main()
{
    Node *root = newNode(1, NULL);
    root->left = newNode(2, root->left);
    root->right = newNode(3, root->right);
    root->right->left = newNode(4, root->right->left);
    root->right->right = newNode(5, root->right->right);
    
    
    cout << "Level order traversal of given tree\n";
    printLevelOrder(root);

    root = flipBinaryTree(root);

    cout << "\nLevel order traversal of the flipped"
            " tree\n";
    printLevelOrder(root);
    return 0;
}