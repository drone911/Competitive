#include <bits/stdc++.h>

using namespace std;

void minRange(int a[], const int n, const int k)
{
    unordered_map<int, int> lastOcc;
    int l =0, r = 0;
    while(r<n) {
        if(r-l+1==k && a[r]-lastOcc[a[r]]+1>=k) {
            cout<<l<<" "<<r<<endl;
            return;
        }
        if(lastOcc.find(a[r]) == lastOcc.end()){
            lastOcc[a[r]] =r;
            r++;
        }else if(a[r]-lastOcc[a[r]]+1>=k){
            lastOcc[a[r]] = r;
            r++;
        } else{
            l = r;
            r++;
        }
    }
    cout<<"NO"<<endl;
}
int main()
{
    int arr[] = {1, 2, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    minRange(arr, n, k);
    return 0;
}