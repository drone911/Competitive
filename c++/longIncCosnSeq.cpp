#include<bits/stdc++.h>

using namespace std;

void longestSubsequence(int a[], int n) {
    unordered_map<int, int> pres;
    pres.reserve(n);
    int index = 0;
    int dp[n];
    memset(dp, 0, sizeof(dp));
    int maxLen = 0;
    for( int i = 0; i<n; i++) {
        if(pres[a[i]-1] == 0) {
            dp[i] = 1;
        } else{
            dp[i] = dp[pres[a[i]-1]]+1;
        }
        pres[a[i]] = i;
        if(dp[i]>maxLen) {
            maxLen = dp[i];
            index = i;
        }
    }
    for(int i = a[index] - maxLen + 1; i<=a[index]; i++) {
        cout<<i<<" ";
    }
    cout<<endl;
}
int main() {
    int a[] = { 3, 10, 3, 11, 4, 5, 6, 7, 8, 12 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    longestSubsequence(a, n); 
    return 0;
}