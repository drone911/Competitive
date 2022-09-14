#include<bits/stdc++.h>
using namespace std;
void inorderTraverse(Node* root, map<int, int> &posMap, int pos){
    if(root == NULL){
        return;
    }
    posMap[pos] = root->data;
    inorderTraverse(root->left, posMap, pos-1);
    inorderTraverse(root->right, posMap, pos+1);
    
}
vector <int> bottomView(Node *root)
{
    map<int, int> posMap;
    inorderTraverse(root, posMap, 0);
    vector<int> bottomOnes;
    for (auto it = posMap.begin(); it != posMap.end(); it++)
    {
        bottomOnes.push_back(it->second);
    }
    return bottomOnes;
}