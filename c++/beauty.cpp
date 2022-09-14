#include<bits/stdc++.h>
using namespace std;

long b[100001];
long decomp[10001];
long Q, N;
long size;

void update(long pos, long val){
    decomp[(pos-1)/size] += val-b[pos-1];
    b[pos-1] = val;
}
long calcMidSum(long x, long y){
    long sum = 0;
    while(x%size!=0 && x!=0 && x<=y){
        sum+=b[x];
        x++;
    }
    while(x+size<=y){
        sum+=decomp[x/size];
        x+=size;
    }
    while(x<=y){
        sum+=b[x];
        x++;
    }
    return sum;
}
void checkAndSet(long *max, long *pos, long *sum, long *x){
    if(*max<*sum){
        *max = *sum;
        *pos = *x;
    }
}
long calcLeftSum(long x){
    long startBlock = x/size;
    long max = 0;
    long maxPos = x;
    long sum = 0;
    while(x%size != size-1 && x>=0){
        cout<<"first"<<endl;
        sum+=b[x];
        checkAndSet(&max, &maxPos, &sum, &x);
        x--;
    }
    
    while(x>=0){
        cout<<"Second"<<endl;
        sum+=decomp[x/size];
        checkAndSet(&max, &maxPos, &sum, &x);
        x-=size;
    }
    if(maxPos/size  == startBlock){
        cout<<"Third1"<<endl;
        
        return max;
    }else{
        cout<<"Third2"<<endl;
        maxPos--;
        sum = max;
        x = maxPos;
        cout<<x<<endl;
        while(x>=0 && x/size == maxPos/size){
            sum+=b[x];
            checkAndSet(&max, &maxPos, &sum, &x);
            x--;
        }   
        return max;
    }
}

long calcRightSum(long y){
    long startBlock = y/size;
    long max = 0;
    long maxPos = y;
    long sum = 0;
    do{
        sum+=b[y];
        checkAndSet(&max, &maxPos, &sum, &y);
        y++;
    }while(y<N && y%size != 0);
    
    while(y<N){
        sum+=decomp[y/size];
        checkAndSet(&max, &maxPos, &sum, &y);
        y+=size;
    }
    if(maxPos/size  == startBlock){
        return max;
    }else{
        maxPos--;
        sum = max;
        y = maxPos;
        while(y<N && y/size == maxPos/size){
            sum+=b[y];
            checkAndSet(&max, &maxPos, &sum, &y);
            y--;
        }   
        return max;
    }
}
void calcSum(long x, long y){
    long mid, left=0, right=0;
     mid = calcMidSum(x, y);
     left = calcLeftSum(x-1);
    //long right = calcRightSum(y+1);
    cout<<"\n"<<left<<" "<<mid<<" "<<right<<"\n";
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>N>>Q;
        size = sqrt(N);
        long blk = -1;
        for(long i = 0; i<N; i++){
            cin>>b[i];
            if(i%size==0){
                blk++;
            }
            decomp[blk]+=b[i];
        }
        char Query;
        while (Q--)
        {
            cin>>Query;
            if(Query == 'Q'){
                long x, y;
                cin>>x>>y;
                calcSum(x-1, y-1);
            }else{
                long pos, v;
                cin>>pos>>v;
                update(pos, v);
            }
        }
    }
    return 0;
}