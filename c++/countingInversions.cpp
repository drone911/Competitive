#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

int temp[100000];

int _merge(int arr[], int l, int mid, int r){
    int invCount = 0;
    int i = l;
    int j = mid+1;
    int k = l;
    while (i<=mid && j<=r)
    {
        if(arr[i]>arr[j]){
            invCount+=mid-i+1;
            temp[k] = arr[j];
            k++;
            j++;
        }else{
            temp[k] = arr[i];
            k++;
            i++;
        }
    }
    while (i<=mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j<=r)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int m = l; m <= r; m++)
    {
        arr[m] = temp[m];
    }
    
    return invCount;
}
int _mergeSort(int arr[], int l, int r){
    
    if(l<r){
        int mid = l+ (r-l)/2;
        int invCount = 0;
        invCount+=_mergeSort(arr, l, mid);
        invCount+=_mergeSort(arr, mid+1, r);
        invCount+=_merge(arr, l, mid, r);
        return invCount;
    }
    return 0;
}
int mergeSort(int arr[], int n){
    return _mergeSort(arr, 0, n-1);
}
int main() 
{ 
    int arr[] = { 1, 20, 6, 4, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int ans = mergeSort(arr, n); 
    cout << "Number of inversions are " << ans; 
    return 0; 
} 
  