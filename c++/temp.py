MOD = int(10e9 + 7)

dp = [-1 for x in range(int(10e5+1))]
dp[0] = 1
dp[1] = 1

def fact(N):    
    if dp[N] != -1:
        return dp[N]
    dp[N] = N*fact(N-1)
    return dp[N]

T = int(input())
for _ in range(T):
    N = int(input())
    print(fact(N))