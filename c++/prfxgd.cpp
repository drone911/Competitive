#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while (T--)
    {
        string s;
        int x, k;
        int max = 0;
        cin>>s;
        cin>>k>>x;
        map<char, int> mp;
        map<char, int>::iterator it tp;
        for(int i = 0; s[i]!='\0';i++){
            tp = mp.find(s[i]);
            if(tp != mp.end()){
                tp->second += 1;
            }else{
                mp.insert(make_pair(s[i], 1));
            }
            if(mp.begin())
        }
    }
    

}