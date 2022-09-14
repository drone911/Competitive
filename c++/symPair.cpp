#include<bits/stdc++.h>
using namespace std;

void findSymPairs(int arr[5][2], int n){
    unordered_map<int, int> mp;
    vector<pair<int, int>> vec;
    for(int i = 0; i<n ; i++) {
        
        if(mp[arr[i][1]] == arr[i][0]){
            vec.push_back(make_pair(arr[i][1], arr[i][0]));
        } else{
                mp[arr[i][0]] = arr[i][1];
        }
    }
    for(int i = 0; i<vec.size(); i++) {
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }
}
int main() 
{ 
    int arr[5][2]; 
    arr[0][0] = 11; arr[0][1] = 20; 
    arr[1][0] = 30; arr[1][1] = 40; 
    arr[2][0] = 5;  arr[2][1] = 3; 
    arr[3][0] = 9;  arr[3][1] = 2; 
    arr[4][0] = 3;  arr[4][1] = 5; 
    findSymPairs(arr, 5); 
} 