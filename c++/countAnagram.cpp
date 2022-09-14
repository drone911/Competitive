#include<bits/stdc++.h>
using namespace std;

int countAnagrams(string str, string pat) {
    int n = str.size();
    int m =pat.size();
    int count = 0;
    for(int i = 0; i<n-m+1; i++) {
        if(is_permutation(str.begin()+i, str.begin()+i+m, pat.begin())) {
            count++;
        }
    }
    return count;
}
int main() {
    string str = "forxxorfxdofr"; 
    string pat = "for"; 
    cout << countAnagrams(str, pat) << endl; 
    return 0; 
}