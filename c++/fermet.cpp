#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n, int k){
    if(n<=1 || n ==4){
        return false;
    }
    if(n<=3){
        return true;
    }
    while (k--)
    {
        int a = 2 + rand()%(n-4);
        if(__gcd(a, n) != 1){
            return false;
        }
        if((long long)pow(a, n-1)%n !=1){
            return false;
        }
    }
    return true;
}
int main(){
    cout<<isPrime(10, 3)<<endl;
    cout<<isPrime(13, 4)<<endl;
    srand((unsigned int) time(NULL));
    cout<< 2 + (rand()%(7-4));
        
}