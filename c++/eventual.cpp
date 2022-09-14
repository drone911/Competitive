#include<bits/stdc++.h>
#define MAX 10001
using namespace std;


int main(){
    cout.sync_with_stdio(false);
    cin.tie(0);
    int T;
    int N;
    char temp;
    cin>>T;
    while (T--)
    {
        cin>>N;
        map<char, int> freq;
        for (int i = 0; i < N; i++)
        {
            cin>>temp;
            freq[temp]++;
        }
        bool flag = false;
        for (auto it = freq.begin(); it != freq.end(); it++)
        {
            if(it->second & 1){
                flag = true;
                break;
            }
        }
        if(flag){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    
    return 0;
}