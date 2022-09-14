#include <bits/stdc++.h>
using namespace std;

struct compare
{
    bool operator()(pair<pair<int, int>, int> const p1, pair<pair<int, int>, int> const p2)
    {
        return p1.second >= p2.second;
    }
};
class Graph
{
    vector<pair<int, int>> *adj;
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, compare> edges;

    int V;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new vector<pair<int, int>>[V];
    }
    void addEdge(int u, int v, int weight)
    {
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight));
        edges.push(make_pair(make_pair(u, v), weight));
    }
    void primMST()
    {
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, compare> Q = edges;
        set<int> visited;
        stack<pair<int, int>> mst;
        
        while (!Q.empty() && visited.size() != this->V)
        {
            auto curr = Q.top();
            Q.pop();
            
            visited.insert(curr.first.first);
            visited.insert(curr.first.second);
            mst.push(make_pair(curr.first.first, curr.first.second));
        }
        if (visited.size() == this->V)
        {
            while(!mst.empty()){
                cout<<mst.top().first<<" "<<mst.top().second<<endl;
                mst.pop();
            }
        }
        else
        {
            cout << "MST not possible" << endl;
        }
    }
};

int main()
{
    Graph g = Graph(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 4, 8);
    g.addEdge(4, 2, 4);
    g.addEdge(2, 3, 3);
    g.addEdge(4, 3, 7);
    g.primMST();
}