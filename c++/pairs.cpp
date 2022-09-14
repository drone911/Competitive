#include <bits/stdc++.h>
using namespace std;

int hsh(int a)
{
    a /= 10;
    return a % 10;
}
inline int convert(int n)
{
    int res = 0;
    int mn = INT_MAX;
    int mx = INT_MIN;
    int tp;
    while (n > 0)
    {
        tp = n % 10;
        mn = min(mn, tp);
        mx = max(mx, tp);
        n = n / 10;
    }
    res = mn * 7 + mx * 11;
    return res;
}
int main()
{
    cin.tie(0);
    cout.sync_with_stdio(false);
    int N;
    cin >> N;
    int arr[N];
    int temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        arr[i] = convert(temp);
    }
    map<int, int> odd;
    map<int, int> even;
    for (int i = 0; i < N; i++)
    {
        if (i & 1)
        {
            odd[hsh(arr[i])]++;
        }
        else
        {
            even[hsh(arr[i])]++;
        }
    }
    int tot=0;
    for (auto i = odd.begin(); i != odd.end(); i++)
    {
        if (i->second > 1)
        {
            if(i->second>2){
                tot+=2;
            }else{
                tot+=1;
            }
        }
    }
    for (auto i = even.begin(); i != even.end(); i++)
    {
        if (i->second > 1)
        {
            if(i->second>2){
                tot+=2;
            }else{
                tot+=1;
            }
        }
    }
    cout << tot << endl;
    return 0;
}
