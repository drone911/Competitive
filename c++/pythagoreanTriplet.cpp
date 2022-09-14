    #include <bits/stdc++.h>
    typedef long long ll;
    using namespace std;

    int main()
    {
        cout.sync_with_stdio(false);
        cin.tie(0);
        int T;
        ll N;
        cin >> T;
        while (T--)
        {
            cin >> N;
            int temp;
            map<ll, int> freq;
            for (ll i = 0; i < N; i++)
            {
                cin >> temp;
                freq[temp*temp]++;
            }
            
            auto &&endFreq = freq.end();
            for (auto it = freq.begin(); it != endFreq; ++it)
            {
                auto ti = it;
                while (ti!=endFreq)
                {   
                    if(it->first == ti->second) {
                        ti++;
                        continue;
                    }
                    ll su = (it->first) + (ti->first);
                    
                    if (freq.find(su)!=endFreq)
                    {
                        cout << "Yes"<<endl;
                        goto END;
                    }
                    ti++;
                }
            }
            cout << "No" << endl;
        END:;
        }
    }
