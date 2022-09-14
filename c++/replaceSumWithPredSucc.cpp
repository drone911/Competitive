#include<bits/stdc++.h>
#define MAX 10001
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* getNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorderTraversalWithInsertion(Node* root, queue<int> &Q) {
    if(root==NULL) {
        return;
    }else{
        inorderTraversalWithInsertion(root->left, Q);
        Q.push(root->data);
        inorderTraversalWithInsertion(root->right, Q);
    }
}
void inorderTraversalWithSet(Node* root, queue<int> &Q) {
    if(root==NULL) {
        return;
    }else{
        inorderTraversalWithSet(root->left, Q);
        root->data = Q.front();
        Q.pop();
        inorderTraversalWithSet(root->right, Q);
    }
}
void replaceNodeWithSumUtil(Node* root) {
    queue<int> Q;
    queue<int> summed;
    inorderTraversalWithInsertion(root, Q);
    int arr[Q.size()+1];
    int n = Q.size();
    int temp, i;
    int pred = Q.front();
    Q.pop();
    summed.push(Q.front());
    for(i = 1; i<n-1; i++) {
        temp = Q.front();
        Q.pop();
        summed.push(pred+Q.front());
        pred = temp;
    }
    summed.push(temp);
    inorderTraversalWithSet(root, summed);
}

void preorderTraversal(Node* root) {
    if(root==NULL) {
        return;
    }else{
        cout<<root->data<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() 
{ 
    // binary tree formation 
    struct Node* root = getNode(1); /*         1        */
    root->left = getNode(2);        /*       /   \      */
    root->right = getNode(3);       /*     2      3     */
    root->left->left = getNode(4);  /*    /  \  /   \   */
    root->left->right = getNode(5); /*   4   5  6   7   */
    root->right->left = getNode(6); 
    root->right->right = getNode(7); 
  
    cout << "Preorder Traversal before tree modification:n"<<" "; 
    preorderTraversal(root); 
  
    replaceNodeWithSumUtil(root); 
  
    cout << "\nPreorder Traversal after tree modification:n"<<" "; 
    preorderTraversal(root); 
  
    return 0; 
} 