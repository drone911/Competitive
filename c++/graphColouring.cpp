#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
class Graph
{
    vector<uint> *adj;
    uint V;

public:
    Graph(uint V)
    {
        this->V = V;
        adj = new vector<uint>[V];
    }
    void addEdge(uint u, uint v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void greedyColoring()
    {
        uint color[this->V];
        bool available[this->V];
        memset(available, true, sizeof(available));
        memset(color, -1, sizeof(color));
        color[0] = 0;
        map<uint, uint> freqUsed;
        freqUsed[0] = 1;
        for (uint i = 1; i < this->V; i++)
        {
            for (uint it : adj[i])
            {
                if (color[it] != -1)
                {
                    available[color[it]] = false;
                }
            }
            for (auto it : freqUsed)
            {
                if (available[it.first])
                {
                    color[i] = it.first;
                    freqUsed[it.first]++;
                    break;
                }
            }
            if (color[i] == -1)
            {
                color[i] = freqUsed.end()->first;
                freqUsed[freqUsed.end()->first]++;
            }

            for (uint it : adj[i])
            {
                if (color[it] != -1)
                {
                    available[color[it]] = true;
                }
            }
        }
        for (uint i = 0; i < this->V; i++)
        {
            cout << i << " " << color[i] << endl;
        }
        cout << "chromatic number: " << freqUsed.size() << endl;
    }
};
int main()
{
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    cout << "Coloring of graph 1 \n";
    g1.greedyColoring();

    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(1, 4);
    g2.addEdge(2, 4);
    g2.addEdge(4, 3);
    cout << "\nColoring of graph 2 \n";
    g2.greedyColoring();

    return 0;
}