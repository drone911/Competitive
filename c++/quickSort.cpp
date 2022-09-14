#include<bits/stdc++.h>
using namespace std;

int findPartition(int arr[], int l, int r){
    int pivot = arr[l];
    int i = l+1;
    int j = r;
    while (i<j)
    {
        while (i<=r && arr[i]<pivot) 
        {
            i++;
        }
        while (arr[j]>pivot)
        {
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}
void quickSort(int arr[], int l, int r){
    if(l<r){
        int partition = findPartition(arr, l, r);
        quickSort(arr,l, partition-1);
        quickSort(arr, partition+1, r);
        
    }
}
int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    for (int elem : arr)
    {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}