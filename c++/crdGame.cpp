#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
inline int getPower(ll n)
{
    int power = 0;
    while (n > 0)
    {
        power += n % 10;
        n /= 10;
    }
    return power;
}
int main()
{
    cin.tie(0);
    cout.sync_with_stdio(false);
    int T;
    int N;
    cin >> T;
    while (T--)
    {
        cin>>N;
        int pointA = 0, pointB = 0;
        ll tempA, tempB;
        for (int i = 0; i < N; i++)
        {
            cin >> tempA >> tempB;
            if (getPower(tempA) == getPower(tempB))
            {
                pointA++;
                pointB++;
            }else if(getPower(tempA)>getPower(tempB)){
                pointA++;
            }else{
                pointB++;
            }
        }
        if(pointA==pointB){
            cout<<"2 "<<pointA<<endl;
        }else if(pointB>pointA){
            cout<<"1 "<<pointB<<endl;
        }else{
            cout<<"0 "<<pointA<<endl;
        }
    }
}