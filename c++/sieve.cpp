#include <bits/stdc++.h> 
using namespace std; 
  
void SieveOfEratosthenes(int n) 
{ 
    bool prime[n+1]; 
    cout<<"ha"<<endl;
    //memset(prime, true, sizeof(prime)); 
    
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p=0; p<=n; p++) 
       if (prime[p]) {

          cout << p <<",";
       }

} 
  
int main() 
{ 
    int n = 500; 
    SieveOfEratosthenes(n);
    return 0; 
} 