#include <bits/stdc++.h>
#define COUNT 256

using namespace std;

bool compareFreq(int patFreq[], int txtFreq[]){
    for(int i =0; i<COUNT; i++) {
        if(patFreq[i]!=txtFreq[i]){
            return false;
        }
    }
    return true;
}
void search(char pat[], char txt[])
{
    int patFreq[COUNT] = {0}, txtFreq[COUNT] = {0};
    const int n = strlen(txt);
    const int m = strlen(pat);

    for(int i =0; i<m; i++) {
        (patFreq[pat[i]])++;
        (txtFreq[txt[i]])++;
    }
    for(int i = m;i<=n;i++) {
        if(compareFreq(patFreq, txtFreq)) {
            cout<<"pattern matched at "<<i-m<<endl; 
        }
        if(i<n){
            (txtFreq[txt[i-m]])--;
            (txtFreq[txt[i]])++;          
        }
    }
}
int main()
{
    char txt[] = "BACDGABCDA";
    char pat[] = "ABCD";
    search(pat, txt);
    return 0;
}