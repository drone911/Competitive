#include<bits/stdc++.h>
using namespace std;

void _tugOfWar(int *arr, int n, int pos, vector<bool> &isIncluded, vector<bool> &soln, int includedElems,int currSum, int total, int &minDiff){
    if(pos>=n) {
        return;
    }
    if(n/2 - includedElems > n - pos){
        return;
    }
    _tugOfWar(arr, n, pos+1, isIncluded, soln, includedElems, currSum, total, minDiff);

    includedElems++;
    isIncluded[pos] = true;
    currSum+=arr[pos];
    if(includedElems == n/2){
        if(abs(total - 2*currSum)<minDiff){
            minDiff =abs(total - 2*currSum);
            for (int i = 0; i < n; i++)
            {
                soln[i] = isIncluded[i];
            }
            
        }
    }else{
        _tugOfWar(arr, n, pos+1, isIncluded, soln, includedElems, currSum, total, minDiff);
    }
    isIncluded[pos] = false;
    includedElems --;
    currSum-=arr[pos];
}
void tugOfWar(int *arr, int n) {
    int total = 0;
    vector<bool> isIncluded(n, false);
    vector<bool> soln(n, false);
    int minDiff = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        total+=arr[i];
    }
    _tugOfWar(arr, n, 0, isIncluded, soln, 0, 0, total, minDiff);
    cout<<"first subset:";
    for (int i = 0; i < n; i++)
    {
        if(soln[i]){
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
    cout<<"second subset:";
    for (int i = 0; i < n; i++)
    {
        if(!soln[i]){
            cout<<arr[i]<<" ";
        }
    }
}
int main() 
{ 
    int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    tugOfWar(arr, n); 
    return 0; 
} 