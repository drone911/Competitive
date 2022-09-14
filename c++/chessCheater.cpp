#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
char result[1000001];
int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);
    uint T, N, K;
    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        cin >> result;
        if (N == K)
        {
            cout << 1 + 2 * (N - 1) << endl;
        }
        else
        {
            uint start = 0;
            for (; start < N; start++)
            {
                if (result[start] == 'W')
                {
                    break;
                }
            }
            if (start == N)
            {
                cout << (K == 0) ? 0 : 1 + (K - 1) * 2;
            }
            else
            {
                uint count = 1;
                uint i;
                char prev = 'W';
                for (i = start + 1; i < N; i++)
                {
                    if (result[i] == 'W')
                    {
                        if (prev == 'W')
                        {
                            count++;
                        }
                        count++;
                        prev = 'W';
                    }
                    else
                    {
                        if (K > 0)
                        {
                            count += 2;
                            K--;
                            prev = 'W';
                        }else{
                            prev = 'L';
                        }
                        
                    }
                }
                if (K > 0)
                {
                    count += 1 + (K - 1) * 2;
                    if (K == start)
                    {
                        count++;
                    }
                }
                cout << count << endl;
            }
        }
    }

    return 0;
}