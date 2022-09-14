#include <bits/stdc++.h>

using namespace std;

int main()
{

    int T;
    long N;
    int *arr;
    cin >> T;
    while (T > 0)
    {
        cin >> N;
        arr = new int[N];
        map<int, int> freq;
        vector<int> ans;

        map<int, int>::reverse_iterator it;
        int i = 0;
        bool flag = false;
        for (int k = 0; k < N; k++)
        {
            cin >> arr[k];
            freq[arr[k]]++;
            if (freq[arr[k]] > 2)
            {
                flag = true;
            }
        }
        if (flag)
        {
            cout << "NO" << endl;
        }
        else
        {
            for (auto ti = freq.begin(); ti != freq.end();)
            {
                ans.push_back(ti->first);
                ti->second--;
                ti++;
                i++;
            }
            it = freq.rbegin();
            while (it->second == 0 && it!=freq.rend())
            {
                it++;
            }
            
            if (it != freq.rend() && ans[i - 1] == it->first)
            {
                cout << "NO" << endl;
            }
            else
            {
                while (it != freq.rend())
                {
                    if (it->second != 0)
                    {
                        ans.push_back(it->first);
                        i++;
                    }
                    it++;
                }
                cout << "YES" << endl;
                for (int j = 0; j < i; j++)
                {
                    cout << ans[j] << " ";
                }
                cout << endl;
            }
        }
        T--;
    }
    return 0;
}