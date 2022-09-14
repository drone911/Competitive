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
bool oneDiff(int a, int b){
    return abs(a-b)==1;
}
bool treeContinuous(Node *root) {
    queue<Node*> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node* curr = Q.front();
        Q.pop();
        if(curr->left){
            if(!oneDiff(curr->data, curr->left->data)){
                return false;
            }
            Q.push(curr->left);
        }
        if(curr->right){
            if(!oneDiff(curr->data, curr->right->data)){
                return false;
            }
            Q.push(curr->right);
        }
    }
    return true;
}
int main() {
    struct Node *root = newNode(3); 
    root->left        = newNode(2); 
    root->right       = newNode(4); 
    root->left->left  = newNode(1); 
    root->left->right = newNode(3); 
    root->right->right = newNode(5); 
    treeContinuous(root)?  cout << "Yes" : cout << "No"; 
    return 0; 
}