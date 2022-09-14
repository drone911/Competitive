#include<bits/stdc++.h>
using namespace std;
void optimum_sequence_jobs(vector<int> V, double P){
    double opt = 0;
    sort(V.begin(), V.end());
    int N = V.size();
    for (int i = 1; i < N; i++)
    {
        opt+=V[i]*pow(1-P, N-i-1);
    }
    
    cout<<opt<<endl;
}

int main() 
{ 
    // For implementation simplicity days are numbered 
    // from 1 to N. Hence 1 based indexing is used 
    vector<int> V{ -1, 3, 5, 4, 1, 2, 7, 6, 8, 9, 10 }; 
  
    // 10% loss per day 
    double P = 0.10; 
  
    optimum_sequence_jobs(V, P); 
  
    return 0; 
} 