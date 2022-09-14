#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

char S[100001];
char P[100001];
char ans[100001];
int freq[26];
inline void clearCount() {
    for (int i = 0; i < 26; i++)
    {
        freq[i] = 0;
    }
}
int main() {
    cin.tie(0);
    cout.sync_with_stdio(false);
    uint T;
    uint N, M, i, j, k, temp;
    bool inFront;
    cin>>T;
    while (T--)
    {
        inFront = true;
        cin>>S>>P;
        N = strlen(S);
        M = strlen(P);
        assert(M<=100000 || N<=100000);
        clearCount();

        for (i = 0; i < N; i++)
        {
            freq[S[i] - 'a']++;
        }
        freq[P[0] - 'a']--;
        for (i = 1; i < M; i++)
        {
            freq[P[i] - 'a']--;
        }
        temp = 1;
        while (temp<M && P[0] == P[temp])
        {
            temp++;
        }
        if(temp<M && P[0]<P[temp]){
            inFront = false;
        }
        j = 0, k = 0;
        uint toAdd;
        for (i = 0; i < 26; i++)
        {
            if (P[0]==(i+'a')) {
                if (inFront) {
                    for (k = 0; k < M; k++)
                    {
                        ans[j++] = P[k];
                    }
                    toAdd = freq[i];
                    while (toAdd--)
                    {
                        ans[j++] = i+'a';
                    }
                }else{
                    toAdd = freq[i];
                    while (toAdd--)
                    {
                        ans[j++] = i+'a';
                    }
                    for (k = 0; k < M; k++)
                    {
                        ans[j++] = P[k];
                    }
                    
                }

            }
            else {
                toAdd = freq[i];
                while (toAdd--)
                {
                    ans[j++] = i+'a';
                }
            }
        }
        ans[j] = '\0';
        cout<<ans<<endl;
    }
    return 0;
}
