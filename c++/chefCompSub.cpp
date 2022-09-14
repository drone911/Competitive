#include <bits/stdc++.h>
#define MAX 200001
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

class Tree
{
public:
    unordered_set<uint> *adj;
    uint N;
    Tree(uint N)
    {
        this->N = N + 1;
        adj = new unordered_set<uint>[N + 1];
    }
    void addEdge(uint u, uint v)
    {
        adj[u].insert(v);
        adj[v].insert(u);
    }
    void removeEdge(uint u, uint v)
    {
        adj[u].erase(v);
        adj[v].erase(u);
    }
};

uint P[MAX], D[MAX], A[MAX], F[MAX];
bool visited[MAX];
Tree *t;

inline void removeAllEdges(uint u)
{
    uint sz = t->adj[u].size();
    for (uint i = 0; i < sz; i++)
    {
        t->removeEdge(u, *(t->adj[u].begin()));
    }
}

void goAndReduce(uint u, uint A, bool visited[], uint day)
{
    visited[u] = true;
    if (F[u] <= A)
    {
        F[u] = 0;
        D[u] = min(D[u], day);
    }
    else
    {
        F[u] -= A;
    }
    auto end = t->adj[u].end();
    for (auto it = t->adj[u].begin(); it != end; it++)
    {
        if (!visited[*it])
        {
            goAndReduce(*it, A, visited, day);
        }
    }
}
void findD(uint N)
{
    for (uint i = 1; i <= N; i++)
    {
        D[i] = UINT_MAX;
    }

    for (uint i = 1; i <= N; i++)
    {
        for (uint j = 1; j <= N; j++)
        {
            visited[j] = false;
        }
        goAndReduce(P[i], A[P[i]], visited, i);
        removeAllEdges(P[i]);
    }
}
int main()
{
    cin.tie(0);
    cout.sync_with_stdio(false);
    uint T, N, tp1, tp2;
    cin >> T;
    while (T--)
    {
        cin >> N;
        t = new Tree(N);
        for (uint i = 0; i < N-1; i++)
        {
            cin >> tp1 >> tp2;
            t->addEdge(tp1, tp2);
        }
        for (uint i = 1; i <= N; i++)
        {
            cin >> P[i];
        }
        for (uint i = 1; i <= N; i++)
        {
            cin >> A[i];
        }
        for (uint i = 1; i <= N; i++)
        {
            cin >> F[i];
        }
        findD(N);
        for (uint i = 1; i <= N; i++)
        {
            if (D[i] == UINT_MAX)
            {
                cout << -1 << " ";
            }
            else
            {
                cout << D[i] << " ";
            }
        }
        cout << endl;
        delete t;
    }

    return 0;
}
