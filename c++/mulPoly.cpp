#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

int* multiplyNaive(int A[], int B[], int m, int n){
    int* res = new int[m+n-1];
    for (int i = 0; i < m+n-1; i++)
    {
        res[i]=0;
    }
    for (int i = 0; i < m; i++)
    {
        for (int k = 0; k < n; k++)
        {
            res[i+k] += A[i]*B[k];
        }
        
    }
    return res;   
}
void printPoly(int poly[], int n) 
{ 
    for (int i=0; i<n; i++) 
    { 
       cout << poly[i]; 
       if (i != 0) 
        cout << "x^" << i ; 
       if (i != n-1) 
       cout << " + "; 
    } 
    cout<<endl;
} 
int main() 
{ 
    // The following array represents polynomial 5 + 10x^2 + 6x^3 
    int A[] = {5, 0, 10, 6}; 
  
    // The following array represents polynomial 1 + 2x + 4x^2 
    int B[] = {1, 2, 4}; 
    int m = sizeof(A)/sizeof(A[0]); 
    int n = sizeof(B)/sizeof(B[0]); 
  
    cout << "First polynomial"<<endl; 
    printPoly(A, m); 
    cout << "nSecond polynomial"<<endl; 
    printPoly(B, n); 
  
    int *prod = multiplyNaive(A, B, m, n); 
    
    cout << "Product polynomial"<<endl; 
    printPoly(prod, m+n-1); 
  
    return 0; 
} 