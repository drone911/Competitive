#include<bits/stdc++.h>
#define MAX 10001
using namespace std;

string checkEvenPalin(string s, int n) {
    if(n%2!=0) {
        return string("NO");
    }
    for(int i = 1; i<n; i++) {
        int lastIndex = 0;
        if(s[i] == s[i-1]) {
            int cnt = 1;
            int j = i+1;
            while(j<n && j-cnt*2>-1 && a[j] == a[j-cnt*2] && lastIndex!=j){
                j++;
            }
            if(lastIndex == j) {
                return 
            }
            lastIndex = j;
            i=j;
        }
    }
}
int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<checkEvenPalin(s, n);
    }
}