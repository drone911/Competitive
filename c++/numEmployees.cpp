#include <bits/stdc++.h>
using namespace std;

int buildCount(char c,unordered_map<char, char> dataSet, unordered_map<char, vector<char>> &revMap, unordered_map<char, int> &cntEmp)
{
    if (cntEmp[c] != 0)
    {       return cntEmp[c];
    }
    else if (revMap.find(c) == revMap.end())
    {
        cntEmp[c] = 0;
        return 0;
    }
    else 
    {
        cntEmp[c] += revMap.find(c)->second.size();
        for (auto ti = revMap.find(c)->second.begin(); ti != revMap.find(c)->second.end(); ++ti)
        {
            cntEmp[c] += buildCount(*ti, dataSet,revMap, cntEmp);
        }
        return cntEmp[c];
    }
}
void findEmployees(unordered_map<char, char> &dataSet)
{
    unordered_map<char, vector<char>> revMap;
    for (auto it = dataSet.begin(); it != dataSet.end(); ++it)
    {
        if(it->first !=it->second)
        revMap[it->second].push_back(it->first);
    }

    unordered_map<char, int> cntEmp;
    for (auto it = dataSet.begin(); it != dataSet.end(); ++it)
    {
        buildCount(it->first, dataSet, revMap, cntEmp);
    }
    for (auto it = cntEmp.begin(); it != cntEmp.end(); ++it)
    {
        cout << it->first << "->" << it->second << endl;
    }
}
int main()
{
    unordered_map<char, char> dataSet;

    dataSet['A'] = 'C';
    dataSet['B'] = 'C';
    dataSet['C'] = 'F';
    dataSet['D'] = 'E';
    dataSet['E'] = 'F';
    dataSet['F'] = 'F';
    findEmployees(dataSet);
    return 0;
}
