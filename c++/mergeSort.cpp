#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int r){
    int i = l;
    int j = mid+1;
    int k = 0;
    int merged[r-l+1];
    while (i<=mid && j<=r)
    {
        if(arr[i]<arr[j]){
            merged[k++] = arr[i++];
        }else{
            merged[k++] = arr[j++];
        }
    }
    while (i<=mid)
    {
        merged[k++] = arr[i++];
    }
    while (j<=r)
    {
        merged[k++] = arr[j++];
    }
    for (int it = 0; it < k; it++)
    {
        arr[l++] = merged[it];
    }
    
}
void mergeSort(int arr[], int l, int r){
    if(l<r){
        int mid = l + (r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}
int main(){
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr,0, n-1);
    for(int elem: arr){
        cout<<elem<<" ";
    }
    cout<<endl;
    return 0;
}