#include<bits/stdc++.h>
using namespace std;

string encrpt(string key, string pat){
    char enc[pat.length()];

    for (int i = 0; i < pat.length(); i++)
    {
        enc[i]= ((pat[i] - 'A'+ (key[i%key.length()] - 'A')%26)+'A');
    }
    return string(enc);
}

int main(){
    string key = "NADIAD", pat = "DHARMSINHDESAIUNIVERSITY";

    cout<<encrpt(key, pat);
}