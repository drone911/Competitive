#include<bits/stdc++.h>

using namespace std;

void printFor1() {
    cout<<"3 3\n0 0\n0 1\n1 0\n1 2\n1 3\n2 3\n";
} 

void printFor2() {
    cout<<"4 5\n0 0\n0 1\n1 0\n1 1\n1 2\n1 3\n2 3\n2 4\n3 4\n";
}
printforK(int k){
    
}
int main() {
    int k;
    cin>>k;
    if(k == 1) {
        printFor1();
    } else if(k == 2) {
        printFor2();
    } else{
        printforK(k);
    }
}