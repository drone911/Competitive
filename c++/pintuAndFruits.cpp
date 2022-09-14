#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while (T--)
    {
        int M, N;
        cin>>N>>M;
        int *F = new int[N+1];
        map<int, int> mp;
        for(int i=1;i<=N;i++){
            cin>>F[i];
            mp.insert(make_pair(F[i], 0));
        }
        for( int i = 1; i<=M; i++){
            
        }
        int price;
        for(int i=1;i<=N;i++){
            cin>>price;
            mp[F[i]] = mp.at(F[i]) + price;
        }
        int min = INT_MAX
        for(auto it= mp.begin(); it!= mp.end(); ++it){
            if(it->second < min){
                min = it->second;
            }
        }
        if(min == INT_MAX){
            cout<<"0"<<endl;
        }else{
            cout<<min<<endl;
        }
        delete []F;
    }
    return 0;
}