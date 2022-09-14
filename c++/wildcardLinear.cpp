#include<bits/stdc++.h>
using namespace std;

bool strmatch(char str[], char pat[], int n, int m) {
    if(m==0) {
        return n==0;
    }
    int index_str = -1;
    int index_pat = -1;
    int i=0, j=0;
    while(i<n) {
        if(j<m && (str[i]==pat[j])||(pat[j]=='?')) {
            i++;
            j++;
        }else if(j<m && pat[i]=='*') {
            index_pat = j;
            index_str = i;
            j++;
        }else if(index_pat!=-1){
            i = index_str+1;
            j = index_pat+1;
            index_str++;
        }else{
            return false;
        }
    }
    while(j<m && pat[j]=='*'){
        j++;
    }
    if(j==m){
        return true;
    }else{
        return false;
    }
}
int main() 
{ 
    char str[] = "baaabab"; 
    char pattern[] = "*****ba*****ab"; 
    // char pattern[] = "ba*****ab"; 
    // char pattern[] = "ba*ab"; 
    // char pattern[] = "a*ab"; 
  
    if (strmatch(str, pattern, 
                 strlen(str), strlen(pattern))) 
        cout << "Yes" << endl; 
    else
        cout << "No" << endl; 
  
    char pattern2[] = "a*****ab"; 
    if (strmatch(str, pattern2, 
                 strlen(str), strlen(pattern2))) 
        cout << "Yes" << endl; 
    else
        cout << "No" << endl; 
  
    return 0; 
} 