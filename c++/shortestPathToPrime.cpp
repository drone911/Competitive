#include <bits/stdc++.h>
#define MAX 9999
using namespace std;
class Graph
{
    vector<int> *adj;
    int V;

public:
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
    int bfs(int s, int e)
    {
        queue<int> Q;
        Q.push(s);
        vector<int> visited(this->V, 0);
        visited[s] = 1;
        while (!Q.empty())
        {
            int curr = Q.front();
            Q.pop();
            for (auto it = adj[curr].begin(); it != adj[curr].end(); it++)
            {
                if (!visited[*it])
                {
                    visited[*it] = visited[curr] + 1;
                    Q.push(*it);
                }
                if (*it == e)
                {
                    return visited[*it] - 1;
                }
            }
        }
        return -1;
    }
};
int numberOfDigit(int num)
{
    int cnt = 0;
    while (num > 0)
    {
        cnt++;
        num /= 10;
    }
    return cnt;
}
void sieveOfPrimes(vector<int> &v)
{
    vector<bool> primes(MAX + 1, true);
    for (int i = 2; i * i <= MAX; i++)
    {
        if (primes[i] == true)
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                primes[j] = false;
            }
        }
    }
    int numberOfDigits = numberOfDigit(MAX);
    for (int i = pow(10, numberOfDigits - 1); i <= MAX; i++)
    {
        if (primes[i] == true)
        {
            v.push_back(i);
        }
    }
}
bool compare(int num1, int num2)
{
    int cmp = 0;
    int digit1;
    int digit2;
    while (num1 > 0 || num2 > 0)
    {
        digit1 = num1 % 10;
        digit2 = num2 % 10;
        if (digit1 - digit2 != 0)
        {
            cmp++;
        }
        num1 = num1 / 10;
        num2 = num2 / 10;
    }
    return (cmp == 1);
}
int shortestPath(int num1, int num2)
{
    vector<int> v;
    sieveOfPrimes(v);
    Graph g = Graph(MAX + 1);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (compare(v[i], v[j]))
            {
                g.addEdge(i, j);
            }
        }
    }
    int num1Index, num2Index;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == num1)
        {
            num1Index = i;
            break;
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == num2)
        {
            num2Index = i;
            break;
        }
    }

    return g.bfs(num1Index, num2Index);
}

int main()
{
    int num1 = 1033, num2 = 8179;
    cout << shortestPath(num1, num2);
    return 0;
}