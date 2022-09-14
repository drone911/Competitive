#include<bits/stdc++.h>
using namespace std;

int L;
long long S;
long Q;
int *bst;
long long nodes;
bool newValue = false;
long value;
void traverse(long root) {
    long left = root*2;
    long right = left + 1;

    if(root<=nodes){
        if(left <= nodes){
        traverse(left);
        } 
        bst[root] = value;
        if(newValue) {
            value++;
        }
        newValue = ! newValue;
        if(right<=nodes){
            traverse(right);
        }
    }
}

void findClosest(long k){
    string result = "";
    for(long i = 2; i<=nodes; i++){
        if(k == bst[i]) {
            k = i;
            break;
        }
    }
    while(k>1){
        if(k%2==0){
            result += 'l';
        }else
        {
            result += 'r';
        }
        k/=2;
    }
    for(auto it = result.rbegin(); it != result.rend(); ++it){
        cout<<*it;
    }
    cout<<endl;
}
void solve(int type, long k){
    if(type == 0 ){
        if(bst[1] == k){
            cout<<"root"<<endl;
        }else{
            findClosest(k);
        }
    }else {
        cout<<bst[k]<<endl;
    }
}
int main()
{
    cin>>L>>S;
    cin>>Q;
    int type;
    long k;    
    long start=1, end=start+ pow(2, L-1) - 1;
    long sum;
    nodes = pow(2, L)-1;
    bst = new int[nodes + 2];
    
    while(1){
        sum = 2*(end*(end+1)/2 - (start)*(start-1)/2) - end;
        if(sum <= S){
            start++;
            end++;
        } else{
            break;
        }
    }
    value = start;
    traverse(1);
    for(int i = 1; i<nodes; i++){
        cout<<bst[i]<<" ";
    }
    while (Q--)
    {
        cin>>type>>k;
        solve(type, k);
    }
    
    return 0;
}
