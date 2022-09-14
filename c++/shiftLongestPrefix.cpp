#include <bits/stdc++.h>
using namespace std;

void preprocessString(string str1, int lps[], int m)
{
    lps[0]=0;
    int j = 1;
    int len = 0;
    while(j<m) {
        if(str1[j]==str1[len]){
            len++;
            lps[j]=len;
            j++;
        }else{
            if(len>0) {
                len = lps[len-1];
            }else{
                lps[j]=0;
                j++;
            }
        }
    }
}
void shiftLongestPrefix(string str1, string str2)
{
    int maxLen = INT_MIN;
    int maxI = INT_MIN;
    str2 = str2 + str2;
    int m = str1.size();
    int n = str2.size();
    // str1 is searched in str2
    int lps[m];
    preprocessString(str1, lps, m);
    int i =0, j = 0;
    while(i<n) {
        if(str1[j]==str2[i]){
            if(j+1>maxLen) {
                maxLen = j+1;
                maxI = i;
            }
            j++;
            i++;
            if(j==m) {
                j = lps[j-1];
            }
        }else{
            if(j>0) {
                j = lps[j-1];
            }else{
                i++;
            }
        }
    }
    cout<<"SHIFT "<<maxI-maxLen+1<<endl;
    cout<<"Prefix "<<str1.substr(0, maxLen);
}
int main()
{
    string str1 = "practicegeeks";
    string str2 = "cecoderpracti";
    shiftLongestPrefix(str1, str2);
    return 0;
}