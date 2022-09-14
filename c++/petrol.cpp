#include<bits/stdc++.h>
#define MAX 1500
using namespace std;
int petrol[MAX];

void backtrack(int currIndex, int count,int N,int currentSum,int sum,vector<bool> &isIncluded, int &diff, vector<bool> &bestRes){
    if(diff>abs(sum - 2*currentSum)){
        for (int i = 0; i < N; i++)
        {
            bestRes[i] = isIncluded[i];
        }
        diff = abs(sum - 2*currentSum);
    }
    if(count>=N || currIndex>=N){
        return;
    }
    count++;
    isIncluded[currIndex] = true;
    currentSum+=petrol[currIndex];
    backtrack(currIndex+1, count, N, currentSum, sum, isIncluded, diff, bestRes);
    isIncluded[currIndex] = false;
    count--;
    currentSum-=petrol[currIndex];
    backtrack(currIndex+1, count, N, currentSum, sum, isIncluded, diff, bestRes);
}
int main() {
    int N;
    cin>>N;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin>>petrol[i];
        sum+=petrol[i];
    }
    vector<bool> isIncluded(N, false);
    int diff = INT_MAX;
    vector<bool> bestRes(N, false);
    backtrack(0, 0,N, 0,sum,isIncluded, diff, bestRes);
    cout<<"first list"<<endl;
    for (int i = 0; i < N; i++)
    {
        if(bestRes[i]){
            cout<<i<<" "<<petrol[i]<<endl;
        }
    }
    cout<<"Second list"<<endl;
    for (int i = 0; i < N; i++)
    {
        if(!bestRes[i]){
            cout<<i<<" "<<petrol[i]<<endl;
        }
    }
    cout<<"best diff: "<<diff;
}