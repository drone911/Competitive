#include<bits/stdc++.h>
using namespace std;
void subarrayDivisibleByK(int arr[], int n, int k) {
    int start = 0, end = 0;
    int maxLen = 0;
    unordered_map<int, int> lastOcc;
    lastOcc.reserve(k);
    for(int i = 0; i<n; i++) {
        int mod = arr[i]%k;
        if(lastOcc.find((k-mod)%k) == lastOcc.end()) {
            end = i;
        } else {
            start = lastOcc[(k-mod)%k]+1;   
        }
        maxLen = max(maxLen, end - start + 1);
        lastOcc[mod] = i;
    }
    cout<<maxLen<<" "<<start<<" "<<end;
}
int main() 
{ 
    int k = 4; 
    int arr[] = {2, 4, 4, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    subarrayDivisibleByK(arr, n, k); 
    return 0; 
}