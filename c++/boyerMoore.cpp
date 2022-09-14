#include<bits/stdc++.h>
#define NO_OF_CHARS 256
using namespace std;

void fillLastOcc(string pat, int m, int lastOcc[]) {
    for(int i = 0 ; i<NO_OF_CHARS; i++) {
        lastOcc[i]=-1;
    }
    for(int i = 0; i<m; i++) {
        lastOcc[pat[i]] = i;
    }
}
void search(string txt, string pat) {

    int n = txt.size();
    int m = pat.size();
    int lastOcc[NO_OF_CHARS];
    fillLastOcc(pat, m, lastOcc);
    int s = 0;
    while(s<=(n-m)) {
        int j = m-1;
        while(j>=0 && pat[j] == txt[s+j]) {
            j--;
        }
        if(j<0) {
            cout<<"pattern at "<<s<<endl;
            s+= (s<m-n)? m-lastOcc[txt[s+m]]:1;
        }else{
            s += max(1, j-lastOcc[txt[j+s]]);
        }
    }
}
int main()  
{  
    string txt= "ABAAABCD";  
    string pat = "ABC";  
    search(txt, pat);  
    return 0;  
}  