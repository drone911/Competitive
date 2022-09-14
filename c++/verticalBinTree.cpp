#include <iostream> 
#include <vector> 
#include <map> 
using namespace std; 
  
// Structure for a binary tree node 
struct Node 
{ 
    int key; 
    Node *left, *right; 
}; 

// A utility function to create a new node 
struct Node* newNode(int key) 
{ 
    struct Node* node = new Node; 
    node->key = key; 
    node->left = node->right = NULL; 
    return node; 
} 
void traverseAndAdd(map<int, vector<int>> &hs, int hashKey, Node* root){
    if(root == NULL) {
        return;
    }
    hs[hashKey].push_back(root->key);

    traverseAndAdd(hs, hashKey - 1, root->left);
    traverseAndAdd(hs, hashKey + 1, root->right);
    
}
void printVerticalOrder(Node* root) {
    map<int, vector<int>> hs;
    int hashKey=0;
    traverseAndAdd(hs, hashKey, root);

    for(auto it = hs.begin(); it!=hs.end(); ++it){
        for(auto i = 0; i<it->second.size(); i++) {
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
}
int main() 
{ 
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 
    cout << "Vertical order traversal is n"<<endl; 
    printVerticalOrder(root); 
    return 0; 
} 