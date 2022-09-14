#include<bits/stdc++.h>

using namespace std;

string isGoodString(string s) {
    int len = s.length();
    for(int i = 1; i<len; i++) {
        if(i!=len-1 && s[i-1]==s[i+1]){
            return string("Yes");
        }else if(s[i-1]==s[i]) {
            return string("Yes");
        }
    }
    return string("No");
}

int main() {
    long T;
    cin>>T;
    while(T--) {
        string s;
        cin>>s;
        cout<<isGoodString(s)<<endl;
    }

    return 0;
}