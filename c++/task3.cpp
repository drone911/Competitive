#include<bits/stdc++.h>
using namespace std;

int solution(string s){
    map<char, int> freq;
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i]]++;
    }
    int count = 0;
    for (auto it = freq.begin(); it != freq.end(); it++)
    {
        if(it->second & 1){
            count++;
        }
    }
    if(s.length()&1){
        count--;
    }
    return count;
}
int main(){
    cout<<solution("aaabbb");
}