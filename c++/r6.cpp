#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

int main() {
    cin.tie(0);
    cout.sync_with_stdio(false);
    int T;
    cin>>T;
    ll N;
    while (T--)
    {
        cin>>N;
        if (N==1) {
            cout<<1<<endl;
        }
        else if (N&1) {
            cout<<2<<endl;
        }
        else {
            cout<<floor((N/2)) + 1<<endl;
        }
    }

    return 0;
}
