#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];

    int i = l;
    for (int j = l; j < r; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}
int kthLargest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int pos = partition(arr, l, r);
        if (r - pos + 1 == k)
        {
            return arr[pos];
        }
        else if (r - pos + 1 < k)
        {
            return kthLargest(arr, l, pos - 1, k - r + pos - 1);
        }
        else
        {
            return kthLargest(arr, pos + 1, r, k);
        }
    }
    else
    {
        return INT_MIN;
    }
}
int main()
{
    int arr[] = {1, 4, 3, -1, 0, 8};
    cout<<kthLargest(arr, 0, sizeof(arr) / sizeof(int) - 1, 3);
    
}