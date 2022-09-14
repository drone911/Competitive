#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int policeThief(char arr[], int n, int k)
{
    vector<int> police;
    vector<int> theif;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 'P'){
            police.push_back(i);
        }else{
            theif.push_back(i);
        }
    }
    int caught = 0;
    int i = 0, j = 0;
    while (i<police.size() && j< theif.size())
    {
        if(abs(police[i] - theif[j])<=k){
            caught++;
            i++;
            j++;
        }else if(police[i]<theif[j]){
            i++;
        }else{
            j++;
        }
    }
    return caught;
}
int main()
{
    int k, n;

    char arr1[] = {'P', 'T', 'T', 'T', 'P', 'P'};
    k = 2;
    n = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Maximum thieves caught: "
         << policeThief(arr1, n, k) << endl;

    return 0;
}