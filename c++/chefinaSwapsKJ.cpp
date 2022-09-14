#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool myCompare(const pair<ll, ll> p1, const pair<ll, ll> &p2)
{
    return p1.first<p2.first;
}

int main()
{
    int T;
    ll N, temp;
    unordered_map<ll, ll> freqA;
    unordered_map<ll, ll> freqTot;
    ll minAll;
    cin >> T;
    while (T--)
    {
        freqA.clear();
        freqTot.clear();
        minAll = LLONG_MAX;
        cin >> N;
        for (ll i = 0; i < N; i++)
        {
            cin >> temp;
            minAll = min(minAll, temp);
            freqA[temp]++;
            freqTot[temp]++;
        }

        for (ll i = 0; i < N; i++)
        {
            cin >> temp;
            minAll= min(minAll, temp);
            freqTot[temp]++;
        }

        auto it = freqTot.begin();
        auto end = freqTot.end();
        auto endA = freqA.end();
        bool flag = false;
        vector<pair<ll, ll>> toSwap;
        unordered_map<ll, ll>::iterator itA;
        ll count = 0;
        while (it != end)
        {
            if ((it->second) & 1)
            {
                flag = true;
                break;
            }
            itA = freqA.find(it->first);

            if (itA == endA)
            {
                count+=(it->second/2);
                toSwap.push_back(make_pair(it->first, it->second / 2));
                it++;
            }
            else
            {
                if (it->second != 2 * itA->second)
                {
                    count+=((ll)abs(it->second - 2 * itA->second) / 2);
                    toSwap.push_back(make_pair(it->first, (ll)abs(it->second - 2 * itA->second) / 2));
                }
                it++;
            }
        }
        if (flag)
        {
            cout << "-1" << endl;
        }
        else
        {
            sort(toSwap.begin(), toSwap.end(), myCompare);
            ll cost1 = 0;
            ll cost2 = 0;
            ll finalCost = 0;
            ll size = toSwap.size();
            ll i = 0;
            ll j = count/2;
            for (int i = 0; i < size; i++)
            {
                cout<<toSwap[i].first<<" "<<toSwap[i].second<<endl;
            }
            
            for (int i = 0; i < size; i++)
            {
                if(j>0){
                    if(toSwap[i].first == minAll){
                        cost1 = toSwap[i].first*toSwap[i].second;
                    }else{
                        cost1 = 2*minAll*toSwap[i].second;
                    }
                    cost2 = toSwap[i].first*toSwap[i].second;
                    j-=toSwap[i].second;
                    if(cost1<cost2){
                        cout<<"minElem"<<endl;
                    }else if(cost1>cost2){
                        cout<<"easey"<<endl;
                    }else{
                        cout<<"equal"<<endl;
                    }
                    finalCost+=min(cost1, cost2);
                }else{
                    break;
                }
            }

            cout << finalCost << endl;
        }
    }
    return 0;
}