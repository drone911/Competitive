#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int main() {
    fast;
    long N, M;
    cin>>N>>M;
    map<pair<long,long>,pair<long,long>> css;
    long id, attr, val, priority;
    for(long i = 0; i<N; i++) {
        cin>>id>>attr>>val>>priority;
        if(css[{id, attr}].first == 0 || css[{id, attr}].second<=priority){
            css[{id, attr}].first = val;
            css[{id, attr}].second = priority;
        }
    }
    for(long i = 0; i<M; i++) {
        cin>>id>>attr;
        cout<<css[{id, attr}].first<<endl;
    }
    return 0;
}