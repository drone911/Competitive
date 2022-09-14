#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int data) {
    Node* n = new Node;
    n->left = NULL;
    n->right = NULL;
    n->data = data;
    return n;
}
bool checkEquality(Node* left, Node* right) {
    if(left->left == NULL || right->right == NULL) {
        if(left->left == NULL && right->right == NULL) {
            return true;
        }else{
            return false;
        }
    }
    if(left->right == NULL || right->left == NULL) {
        if(left->right == NULL && right->left == NULL) {
            return true;
        }else{
            return false;
        }
    }
    return checkEquality(left->left, right->right) && checkEquality(left->right, right->left);
}
bool isFoldable(Node *root) {
    if(root->left == NULL || root->right ==NULL) {
        if(root->left == NULL && root->right ==NULL) {
            return true;
        }else{
            return false;
        }
    }else{
        return checkEquality(root->left, root->right);
    }
}
int main() {
    struct Node *root = newNode(3); 
    root->left        = newNode(2); 
    root->right       = newNode(4); 
    root->left->left  = newNode(1); 
    root->right->right = newNode(5); 
    root->right->right->left = newNode(7); 
    isFoldable(root)?  cout << "Yes" : cout << "No"; 
    return 0; 
}