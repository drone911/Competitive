#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin>>N;
    vector<char> brides;
    map<char, int> grooms;
    char temp;
    for (int i = 0; i < N; i++)
    {
        cin>>temp;
        brides.push_back(temp);
    }
    
    for (int i = 0; i < N; i++)
    {
        cin>>temp;
        grooms[temp]++;
    }
    int i;
    for (i = 0; i < N; i++)
    {
        if(grooms[brides[i]] == 0){
            break;
        }
        grooms[brides[i]]--;
    }
    cout<<N-i<<endl;
    return 0;
}