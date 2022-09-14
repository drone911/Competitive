#include<bits/stdc++.h>
using namespace std;

void shellSort(int arr[], int n){
    for (int gap = n/2; gap > 0; gap/=2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;
            while (j>=gap && arr[j-gap]>temp)
            {
                arr[j] = arr[j-gap];
                j-=gap;
            }
            arr[j] = temp;
        }
    }
}
int main(){
    int arr[] = {10, 30, 20, 50 ,11};
    shellSort(arr, sizeof(arr)/sizeof(arr[0]));
    for(int elem: arr){
        cout<<elem<<" ";
    }
    cout<<endl;
}