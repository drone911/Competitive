#include <bits/stdc++.h>
using namespace std;
int mergeSubArraySum(int arr[], int l, int mid, int r){
    int sum = 0;
    int maxLeftSum = INT_MIN;
    for (int i = mid; i >= l; i--)
    {
        sum+=arr[i];
        if(sum>maxLeftSum){
            maxLeftSum = sum;
        }
    }
    int maxRightSum = INT_MIN;
    sum = 0;
    for (int i = mid; i <= r; i++)
    {
        sum+=arr[i];
        if(sum>maxRightSum){
            maxRightSum = sum;
        }
    }
    return max(maxLeftSum+maxRightSum, max(maxLeftSum, maxRightSum));
}
int maxSubArraySum(int arr[], int l, int r){
    if(l==r){
        return arr[l];
    }else{
        int mid = l + (r-l)/2;
        return max(maxSubArraySum(arr, l, mid), max(maxSubArraySum(arr, mid+1, r), mergeSubArraySum(arr, l, mid, r)));
    }
}
int main()
{
    int arr[] = {2, 3, 4, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, 0, n - 1);
    cout<<max_sum<<endl;
    return 0;
}
