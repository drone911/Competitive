#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

int firstFit(int weight[], int n, int c)
{
    int res = 0;
    multiset<int> remBins;
    multiset<int>::iterator bestFitBin;
    for (int i = 0; i < n; i++)
    {   
        bestFitBin=remBins.upper_bound(weight[i]);
        if(bestFitBin==remBins.end()){
            res++;
            remBins.insert(c-weight[i]);
        }else{
            int val = *bestFitBin;
            remBins.erase(bestFitBin);
            remBins.insert(val-weight[i]);
        }
    }
    return res;
}
int main()
{
    int weight[] = {2, 5, 4, 7, 1, 3, 8};
    int c = 10;
    int n = sizeof(weight) / sizeof(weight[0]);
    cout << "Number of bins required in Next Fit : "
         << firstFit(weight, n, c);
    return 0;
}