#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;


int main() {
    cin.tie(0);
    cout.sync_with_stdio(false);
    int N;
    cin>>N;
    int maxIndex;
    int maxValue = INT_MIN;
    vector<int> oppo(N);
    for (int i = 0; i < N; i++)
    {
        cin>>oppo[i];
        if (maxValue<=oppo[i]) {
            maxValue = oppo[i];
            maxIndex = i;
        }
    }
    uint prize = 0;
    int size = N;
    int left, right;
    while (size>1)
    {

        if (maxIndex>0) {
            left = oppo[maxIndex-1];
        }
        else {
            left = -1;
        }

        if (maxIndex<size-1) {
            right = oppo[maxIndex+1];
        }
        else {
            right = -1;
        }
        if (left == maxValue) {
            if (size -1 - maxIndex >0 && maxIndex-1 >0) {
                if (oppo[maxIndex - 2] < oppo[maxIndex + 1]) {
                    maxIndex--;
                    if (maxIndex<size-1) {
                        right = oppo[maxIndex+1];
                    }
                    else {
                        right = -1;
                    }
                }
            }
            else if (maxIndex-1 < (size - 1) - maxIndex) {
                maxIndex--;
                if (maxIndex<size-1) {
                    right = oppo[maxIndex+1];
                }
                else {
                    right = -1;
                }
            }

        }
        if (left>right) {

            prize+=maxValue*left;
            if (maxIndex -2 >=0) {
                prize+=oppo[maxIndex - 2];
            }
            oppo.erase(oppo.begin() + (maxIndex - 1));
            maxIndex--;
        }
        else {
            prize+=maxValue*right;
            if (maxIndex +2 <=size-1) {
                prize+=oppo[maxIndex + 2];
            }
            oppo.erase(oppo.begin() + (maxIndex + 1));
            cout<<oppo.size()<<endl;
        }
        size--;
        for (int i = 0; i < size; i++)
        {
            cout<<i<<" "<<oppo[i]<<endl;
        }
        //cout<<"ha "<<prize<<endl;


    }
    prize+=oppo[0];
    cout<<prize;
    return 0;
}
