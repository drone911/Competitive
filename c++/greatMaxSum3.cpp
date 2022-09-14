#include<bits/stdc++.h>
using namespace std;


int maxSumDivThree(vector<int>& nums) {

    // dp vector for storing number with remainder {0,1,2}
    vector<int> dp={0,INT_MIN};
    
    for(auto i: nums){
        vector<int> tmp(2);
        
        for(int j=0;j<2;j++){
            tmp[(j+i)%2]=max(dp[(j+i)%2],dp[j]+i);
        }
        for (auto i: tmp) {

        cout<<i<<" ";
        }
        cout<<endl;
        dp=tmp;
    }
    
    // Returning the Greatest sum
    return dp[0];
}

int main() {

    vector<int> vv = vector<int>{1, 5};
    for (auto i: vv) {
        cout<<i<<" ";
    }
    cout<<endl;
    maxSumDivThree(vv);
    return 0;
}