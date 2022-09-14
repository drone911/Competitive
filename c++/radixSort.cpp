#include <bits/stdc++.h>
using namespace std;

void radixSortUtil(int arr[], int n, int exp)
{
    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 0; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}
void radixSort(int arr[], int n)
{
    int maxElem = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxElem = max(maxElem, arr[i]);
    }
    for (int i = 1; maxElem / i > 0; i *= 10)
    {
        radixSortUtil(arr, n, i);
    }
}
int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    for (int elem : arr)
    {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}