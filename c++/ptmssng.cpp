#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    cout.sync_with_stdio(false);
    cin.tie(0);
    int T;
    ll N;
    ll tot;
    ll temp1, temp2;
    cin>>T;
    while (T--)
    {
        cin>>N;
        tot = 4*N-1;
        unordered_map<int, int> freq1,freq2;
        for (ll i = 0; i < tot; i++)
        {
            cin>>temp1>>temp2;
            freq1[temp1]++;
            freq2[temp2]++;
            if(freq1[temp1] == 2){
                freq1.erase(temp1);
            }
            if(freq2[temp2] == 2){
                freq2.erase(temp2);
            }
        }
        auto end1= freq1.end();
        auto end2= freq2.end();
        for (auto it = freq1.begin(); it != end1; it++)
        {
            if(it->second&1){
                temp1 = it->first;
                break;
            }
        }
        for (auto it = freq2.begin(); it != end2; it++)
        {
            if(it->second&1){
                temp2 = it->first;
                break;
            }
        }
        cout<<temp1<<" "<<temp2<<endl;
    }
    
}