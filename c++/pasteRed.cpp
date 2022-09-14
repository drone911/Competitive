#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

void findAnswer(uint index, string output, uint outputSize, string str2, uint M, uint &sum) {
    int thisSum = 0;
    while (index<outputSize && output[index] != str2[0])
    {
        thisSum+=1;
    }
    if (index<outputSize) {
        return;
    }
    thisSum+=1;
    int j = 1;
    for (int i = index+1; i < outputSize; i++)
    {
        if (output[i] == str2[0]) {
            i+=findAnswer(i, output, outputSize, str2, M, sum);
        }
        else {
            if (j<M) {
                if (output[i] != str2[j]) {
                    thisSum++;
                }
                j++;
            }else{
                break;
            }
        }
    }
    if (j==M) {
        return M;
    }
    else {
        return 
    }
}
uint arr[36];
int main() {
    cin.tie(0);
    cout.sync_with_stdio(false);
    string str;
    string str2 = "";
    string output = "";
    getline(cin, str);
    cin>>str2;
    uint N = str.length();
    uint M = str2.length();
    uint j = 0;
    uint sum=0;
    for (int i = 0; i < N; i++)
    {
        if (str2.find(str[i]) != string::npos) {
            output+=str[i];
        }
    }
    findAnswer(0, output, (uint)output.size(), str2, M, sum);

    cout<<sum;
    return 0;
}
