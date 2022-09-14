#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
string A = ".*.****.*";
string E = "*********";
string I = "***.*.***";
string O = "****.****";
string U = "*.**.****";
inline char match(string toMatch) {
    if (A.compare(toMatch)==0) {
        return 'A';
    }
    else if (E.compare(toMatch)==0) {
        return 'E';
    }
    else if (I.compare(toMatch)==0) {
        return 'I';
    }
    else if (O.compare(toMatch)==0) {
        return 'O';
    }
    else if (U.compare(toMatch)==0) {
        return 'U';
    }
    else {
        return 'Z';
    }
}
char mat[3][100001];
int main() {
    cin.tie(0);
    cout.sync_with_stdio(false);
    ll N;
    cin>>N;
    for (int i = 0; i < 3; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            cin>>mat[i][j];
        }

    }
    string output = "";
    string toMatch = "";
    ll j = 0;
    ll count = 0;
    int i = 0;
    while (j<N)
    {
        i = 0;
        if (mat[i][j] == '#') {
            output+="#";
            j++;
        }
        else {
            toMatch = "";
            while (i<3)
            {
                count = 0;
                while (count<3 && count+j<N)
                {
                    toMatch+=mat[i][count+j];
                    count++;
                }
                i++;
            }
            if (match(toMatch) != 'Z') {
                output+=match(toMatch);
                j+=3;
            }
            else {
                j+=1;
            }
        }
    }
    cout<<output;
    return 0;
}
