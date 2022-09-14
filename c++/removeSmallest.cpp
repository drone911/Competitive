#include <bits/stdc++.h>
using namespace std;
int arr[51];
int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int n;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (n == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            sort(arr, arr + n);
            int count = n;
            for (int i = 0; i < n - 1; i++)
            {
                if (arr[i + 1] - arr[i] <= 1)
                {
                    count--;
                }
            }
            if (count == 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}