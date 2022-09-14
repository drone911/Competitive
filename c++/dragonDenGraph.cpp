#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class Graph
{
public:
    set<ll> *adj;
    ll N;
    vector<ll> *parent;
    void addEdge(ll u, ll v)
    {
        adj[u].insert(v);
    }
    void initialiseLeft(ll height[], ll N)
    {
        adj = new set<ll>[N];
        this->N = N;
        parent = new vector<ll>(N, -1);

        ll curr = N - 2;
        ll currParent = N - 1;
        while (curr >= 0)
        {
            while (currParent != -1)
            {
                if (height[curr] < height[currParent])
                {

                    addEdge(currParent, curr);
                    (*parent)[curr] = currParent;
                    currParent = curr;
                    break;
                }
                else
                {
                    currParent = (*parent)[currParent];
                }
            }
            if (currParent == -1)
            {
                currParent = curr;
            }
            curr--;
        }
    }
    void initialiseRight(ll height[], ll N)
    {
        adj = new set<ll>[N];
        this->N = N;
        parent = new vector<ll>(N, -1);

        ll curr = 1;
        ll currParent = 0;
        while (curr < N)
        {
            while (currParent != -1)
            {

                if (height[curr] < height[currParent])
                {

                    addEdge(currParent, curr);
                    (*parent)[curr] = currParent;
                    currParent = curr;
                    break;
                }
                else
                {
                    currParent = (*parent)[currParent];
                }
            }

            if (currParent == -1)
            {
                currParent = curr;
            }

            curr++;
        }
    }
    void printGraph()
    {
        for (int i = 0; i < this->N; ++i)
        {
            auto lst = this->adj[i];
            cout << endl
                 << "Adjacency list of vertex "
                 << i << endl;

            for (auto itr = lst.begin(); itr != lst.end(); ++itr)
                cout << *itr << " ";
            cout << endl;
        }
    }
};

bool dfs(ll start, ll end, ll spice[], Graph *g, bool visited[], ll &sum)
{
    visited[start] = true;
    sum += spice[start];
    if (start == end)
    {
        return true;
    }
    auto ending = g->adj[start].end();
    for (auto it = g->adj[start].begin(); it != ending; it++)
    {
        if (!visited[*it])
        {
            if (dfs(*it, end, spice, g, visited, sum))
            {
                return true;
            }
        }
    }
    sum -= spice[start];
    return false;
}
int main()
{
    cin.tie(0);
    cout.sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    ll height[N];
    ll spice[N];
    for (ll i = 0; i < N; i++)
    {
        cin >> height[i];
    }
    for (ll i = 0; i < N; i++)
    {
        cin >> spice[i];
    }
    //create left graph
    Graph leftGraph = Graph();
    leftGraph.initialiseLeft(height, N);
    //create right graph
    Graph rightGraph = Graph();
    rightGraph.initialiseRight(height, N);
    int type;
    ll start, end;
    ll pos, newSpice;
    for (ll i = 0; i < Q; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> pos >> newSpice;
            spice[pos - 1] = newSpice;
        }
        else
        {
            cin >> start >> end;
            start--;
            end--;
            if (start == end)
            {
                cout << spice[start] << endl;
            }
            else if (height[start] <= height[end])
            {
                cout << -1 << endl;
            }
            else
            {
                bool visited[N] = {false};
                ll sum = 0;
                Graph *g;
                if (start < end)
                {
                    g = &rightGraph;
                }
                else
                {
                    g = &leftGraph;
                }
                if (dfs(start, end, spice, g, visited, sum))
                {
                    cout << sum << endl;
                }
                else
                {
                    cout << -1 << endl;
                }
            }
        }
    }
    return 0;
}
