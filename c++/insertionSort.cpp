#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    for (int i = 2; i < n; i++)
    {
        int temp = arr[i];
        int j = i;
        while (arr[j-1]>temp)
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
    }
    
}
int main(){
    int arr[] = {INT_MIN, 2,4,24,33, 0};
    insertionSort(arr, sizeof(arr)/sizeof(arr[0]));
    for(int elem: arr){
        cout<<elem<<" ";
    }
    cout<<endl;
}