#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main() {
    cin.tie(0);
    cout.sync_with_stdio(false);
    ll N, T, Q, value;
    char symbol;
    unordered_map<ll, ll> freq;
    cin>>N;
    for (ll i = 0; i < N; i++)
    {
        cin>>value;
        freq[value]++;
    }
    cin>>Q;
    ll count = 0;
    ll count4s = 0;
    for (auto it = freq.begin(); it != freq.end(); it++)
    {

        if (it->second&1) {
            count+=(it->second-1);
        }
        else {
            count+=it->second;
        }
        if(it->second>=4){
            count4s++;
        }
    }
    while (Q--)
    {
        cin>>symbol;
        cin>>value;
        if (symbol == '+') {
            
            freq[value]++;
            if(freq[value]==4){
                count4s++;
            }
            if(!(freq[value]&1)){
                count+=2;
            }
        }
        else {
            freq[value]--;
            if(freq[value]==3){
                count4s--;
            }
            if(freq[value]&1){
                count-=2;
            }
        }

        if (count>=8 && count4s>0) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }

    return 0;

}