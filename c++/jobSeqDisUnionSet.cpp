#include <bits/stdc++.h>
using namespace std;

class Job
{
public:
    char id;
    int deadLine;
    int profit;
    Job(char id, int deadLine, int profit) : id(id), deadLine(deadLine), profit(profit) {}
};

bool comparator(Job a, Job b)
{
    return a.profit > b.profit;
}
class DisjointSet
{
public:
    int *parent;
    int N;
    DisjointSet(int N)
    {
        this->N = N;
        parent = new int[N];
        for (int i = 0; i < N; i++)
        {
            parent[i] = i;
        }
    }
    void merge(int u, int v)
    {
        parent[v] = u;
    }
    int find(int u)
    {
        if (u == parent[u])
        {
            return u;
        }
        else
        {
            parent[u] = find(parent[u]);
            return parent[u];
        }
    }
};
void printJobScheduling(Job jobs[], int N)
{
    sort(jobs, jobs + N, comparator);
    int maxDead = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        maxDead = max(maxDead, jobs[i].deadLine);
    }
    DisjointSet ds(maxDead + 1);
    for (int i = 0; i < N; i++)
    {
        int toInsert = ds.find(jobs[i].deadLine);
        if(toInsert>0){
            ds.merge(ds.find(toInsert-1), toInsert);
            cout<<jobs[i].id<<" ";
        }
    }
    cout<<endl;
}
int main()
{
    Job arr[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following jobs need to be "
         << "executed for maximum profit\n";
    printJobScheduling(arr, n);
    return 0;
}