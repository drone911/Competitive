#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    long S, N;
    cin >> T;
    while (T > 0)
    {
        cin >> S >> N;
        long count = 0;
        if (N <= S)
        {
            int temp = S / N;
            count += temp;
            S = S % N;
        }
        if (S > 1)
        {

            if (S & 1)
            {
                count += 2;
            }
            else
            {
                count++;
            }
            S = 0;
        }
        else
        {
            if (S)
            {
                count++;
            }
        }
        cout << count << endl;
        T--;
    }
    return 0;
}