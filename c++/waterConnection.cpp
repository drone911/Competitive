#include<bits/stdc++.h>
using namespace std;


int main() 
{ 
    n = 9, p = 6; 
  
    memset(rd, 0, sizeof(rd)); 
    memset(cd, 0, sizeof(cd)); 
    memset(wt, 0, sizeof(wt)); 
  
    int arr[][3] = { { 7, 4, 98 }, 
                    { 5, 9, 72 }, 
                    { 4, 6, 10 }, 
                    { 2, 8, 22 }, 
                    { 9, 7, 17 }, 
                    { 3, 1, 66 } }; 
  
    solve(arr); 
    return 0; 
} 