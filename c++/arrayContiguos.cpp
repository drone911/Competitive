#include <bits/stdc++.h>

using namespace std;

bool areElementsContiguous(int a[], int n)
{
    unordered_map<int, int> freq;
    int dup = 0;
    for (int i = 0; i < n; i++)
    {
        if (freq.find(a[i]) != freq.end())
        {
            dup++;
        }
        freq[a[i]] += 1;
    }
    int index = -1;
    for(int i = 0; i<n ; i++) {
        if(freq.find(a[i]-1) == freq.end()) {
            index = i;
            break;
        }
    }
    int i =0;
    while(i<n-dup) {
        if(freq[a[index]+i] == 0){
            return false;
        }else{
            i++;
        }
    }
    return true;
}
int main()
{
    int arr[] = {10, 14, 10, 12, 12, 13, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (areElementsContiguous(arr, n))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}