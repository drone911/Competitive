#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while (T--)
    {
        int N;
        cin>>N;
        int start = 0;
        short temp;
        int i;
        for(i=0;i<N;i++){
            cin>>temp;
            if(temp){
                start = i;
                break;
            }
        }
        bool flag = false;
        for(i=start+1;i<N;i++){
            cin>>temp;
            if(temp){
                if(i-start<6){
                    flag = true;
                }else{
                    start = i;
                }
            }
        }
        if(flag){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    
}