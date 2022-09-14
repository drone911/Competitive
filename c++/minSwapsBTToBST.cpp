#include<bits/stdc++.h>

using namespace std;

void inorder(int a[], vector<int> &v, int n, int index) {
    if(index>=n) 
        return;
    else{
        inorder(a, v, n, 2*index+1);
        v.push_back(a[index]);
        inorder(a, v, n, 2*index +2);
    }
}
int minSwaps(vector<int> v) {
    vector<pair<int , int>> temp(v.size());
    for(int i = 0;i<v.size(); i++) {
        temp[i].first = v[i];
        temp[i].second = i;
    }
    sort(temp.begin(), temp.end());
    int ans = 0;
    for(int i =0; i<temp.size(); i++) {
        if(i == temp[i].second){
            continue;
        }else{
            swap(temp[i].first, temp[temp[i].second].first);
            swap(temp[i].second, temp[temp[i].second].second);
            ans++;
            i--;
        }
    }
    return ans;
}
int main() {
    int a[] = { 5, 6, 7, 8, 9, 10, 11 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    std::vector<int> v; 
    inorder(a, v, n, 0); 
    cout << minSwaps(v) << endl; 
    return 0;
}