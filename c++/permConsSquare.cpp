#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    vector<int> *adj;
    int V;

    Graph(int V)
    {
        this->V = V;
        adj = new vector<int>[V];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};
bool _printHam(int s, Graph *graph, list<int> &soln, vector<bool> &visited, int visitedElems)
{
    if (visitedElems == graph->V)
    {
        return true;
    }
    auto end = graph->adj[s].end();
    for (auto it = graph->adj[s].begin(); it != end; it++)
    {
        if(!visited[*it]){
            soln.push_back(*it);
            visited[*it] = true;
            if(_printHam(*it, graph, soln, visited, visitedElems + 1)){
                return true;
            }else{
                soln.pop_back();
                visited[*it] = false;    
            }
        }
    }
    return false;
}
void printHam(Graph *graph)
{
    bool flag = false;
    list<int> soln;
    for (int i = 1; i < graph->V; i++)
    {
        soln.clear();
        vector<bool> visited(graph->V, false);
        visited[0] = true;

        if (_printHam(i, graph, soln, visited, 1))
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        
        while (!soln.empty())
        {
            cout << soln.front() << " ";
            soln.pop_front();
        }
    }
    else
    {
        cout << "Not Possible";
    }
    cout << endl;
}
void printRequiredPerm(int n)
{
    Graph *graph = new Graph(n + 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            float num = sqrt(i + j);
            int num2 = (int)num;
            if (num == num2)
            {
                graph->addEdge(i, j);
            }
        }
    }
    printHam(graph);
}
int main()
{
    int n = 25;
    printRequiredPerm(n);
}