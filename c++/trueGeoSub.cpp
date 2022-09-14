#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
class Line
{
public:
    ull slope, intercept;
    Line(ull slope, ull intercept) : slope(slope), intercept(intercept) {}
};
class compare
{
public:
    bool operator()(pair<uint, uint> &P1, pair<uint, uint> &P2)
    {
        return P1.first * P2.second <= P2.first * P1.second;
    }
};
inline ll nc3(uint n)
{
    return ((n) * (n - 1) * (n - 2)) / 6;
}
uint V[3001];
int main()
{
    cin.tie(0);
    cout.sync_with_stdio(false);
    uint T, N, K, C;
    pair<uint, uint> current;
    ll count = 0;
    ull a, b;
    uint c;
    bool flag;
    cin >> T;
    unordered_map<ll, vector<Line>> countLines;
    priority_queue<pair<uint, uint>, vector<pair<uint, uint>>, compare> sizes;
    priority_queue<pair<uint, uint>, vector<pair<uint, uint>>, compare> sizesCopy;
    
    while (T--)
    {
        while (!sizes.empty())
        {
            sizes.pop();
        }
        while (!sizesCopy.empty())
        {
            sizesCopy.pop();
        }
        
        countLines.clear();
        cin >> N >> C >> K;
        for (uint i = 0; i < N; i++)
        {
            cin >> a >> b >> c;
            countLines[c - 1].push_back(Line(a, b));
        }
        auto end = countLines.end();
        for (uint i = 0; i < C; i++)
        {
            cin >> V[i];
        }
        for (auto it = countLines.begin(); it != end; it++)
        {
            sizes.push(make_pair(it->second.size(), V[it->first]));
        }
        
        while (!sizes.empty())
        {
            current = sizes.top();
            sizes.pop();
            if(current.first == 0 ){
                break;
            }
            else if (K >= current.second )
            {
                K -= current.second;
                current.first--;
                sizes.push(current);
            }else{
                sizesCopy.push(current);
            }
        }
        while (!sizes.empty())
        {
            sizesCopy.push(sizes.top());
            sizes.pop();
        }
        
        if (sizesCopy.empty())
        {
            cout << 0 << endl;
        }
        else
        {
            count = 0;
            while (!sizesCopy.empty())
            {
                current = sizesCopy.top();
                sizesCopy.pop();
                if (current.first > 2)
                {
                    count += nc3(current.first);
                }
                else
                {
                    break;
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}
