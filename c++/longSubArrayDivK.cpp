#include<bits/stdc++.h>

using namespace std;

int longSubarrWthSumDivByK(int arr[], int n, int k) {
    map<int, int> firstOcc;
    int mod[n+1];
    mod[0] = arr[0]%k;
    firstOcc[mod[0]] = 0;
    for(int i = 1; i<n; i++) {
        mod[i] = (mod[i-1]+arr[i])%k;
    }
    if(mod[n-1] == 0) {
        return n;
    }else{
        int maxLen = INT_MIN;
        for(int i = 0; i<n; i++) {
            if(mod[i] == 0) {
                maxLen = max(maxLen, i+1);
            else if(firstOcc.find(mod[i])==firstOcc.end()){
                firstOcc[mod[i]] = i;
            }else{
                maxLen = max(maxLen, i - firstOcc[mod[i]]);
            }
        }
        return maxLen;
    }
}
int main() 
{ 
    int arr[] = {2, 7, 6, 1, 4, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 
      
    cout << "Length = "
         << longSubarrWthSumDivByK(arr, n, k); 
           
    return 0;      
} 