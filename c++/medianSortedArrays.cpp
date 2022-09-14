#include<bits/stdc++.h>
using namespace std;

int median(int arr[], int n){
    if(n%2==0){
        return (arr[n/2]+arr[n/2-1])/2;
    }else{
        return arr[n/2];
    }
}
int getMedian(int arr1[], int arr2[], int n){
    if(n==1){
        return (arr1[0] + arr2[0])/2;
    }
    if(n==2){
        return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1]))/2;
    }
    int mid = n/2;
    int median1 = median(arr1, n);
    int median2 = median(arr2, n);

    if(median1 == median2){
        return median1;
    }else if(median1 > median2){
        if(n&1){
            return getMedian(arr2+n/2, arr1, n/2+1);
        }
        return getMedian(arr2+n/2-1, arr1, n/2+1);
    }else{
        if(n&1){
            return getMedian(arr1+n/2, arr2, n/2+1);
        }
        return getMedian(arr1+n/2-1, arr2, n/2+1);
    }
}
int main() 
{ 
    int ar1[] = {1, 2, 3, 6}; 
    int ar2[] = {9, 10, 11, 12}; 
    int n1 = sizeof(ar1) /  
             sizeof(ar1[0]); 
    int n2 = sizeof(ar2) /  
             sizeof(ar2[0]); 
    if (n1 == n2) 
        cout << "Median is "
             << getMedian(ar1, ar2, n1); 
    else
        cout << "Doesn't work for arrays " 
             << "of unequal size"; 
    return 0; 
} 