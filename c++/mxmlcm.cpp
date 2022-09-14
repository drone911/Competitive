#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to n-1 
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 
  

int main(){
    int T;
    cin>>T;
    while(T--){
        int M, N;
        cin>>N>>M;
        set<int> s ;
        int n;
        s.insert(1);
        for(int i = 0 ;i<N;i++){
            cin>>n;
            
            while (n%2 == 0){
                s.insert(2);
                n = n/2;
            }
            for (int i = 3; i <= sqrt(n); i = i+2){
                while (n%i == 0){
                    s.insert(i);
                    n = n/i;
                }
            }
            s.insert(n);
        }
        auto it =  s.end();
        while(M>1){
            if(isPrime(M)){
                if(*it<M){
                    break;
                }
                else if(*it == M){
                    M--;
                    --it;
                }
                else{
                    M--;
                }
            }else{
                M--;
            }
        }
        cout<<M<<"\n";
    }
}