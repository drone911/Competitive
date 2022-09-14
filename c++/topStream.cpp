#include<bits/stdc++.h>

using namespace std;

void kTop(int arr[], int n, int k){
    vector<int> vec(k+1,0);
    unordered_map<int, int> freq;
    for(int i = 0; i<n; i++) {
        freq[arr[i]]++;
        vec[k] = arr[i];
        auto it = find(vec.begin(), vec.end()-1, arr[i]);
        for(int j = distance(vec.begin(), it) - 1; j>=0 ; --j) {
            if(freq[vec[j]]<freq[vec[j+1]]) {
            
                swap(vec[j], vec[j+1]);
            }else if(freq[vec[j]]==freq[vec[j+1]] && vec[j]>vec[j+1]){
                swap(vec[j], vec[j+1]);
            }
            else{
                break;
            }
        }
        for(int i = 0; i<k && vec[i]!=0; i++){
            cout<<vec[i]<<" ";
        }
    }
    cout<<endl;
}
int main() {
    int k = 4; 
    int arr[] = { 5, 2, 1, 3, 2 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    kTop(arr, n, k); 
    return 0;
}