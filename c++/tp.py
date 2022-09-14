N, M = (int(x) for x in input().split())
mat = []

for x in range(N):
    mat.append([int(x) for x in input().split()])

dp = [[-1 for x in range(M)] for y in range(N)]

dp[0][0] = mat[0][0]

for y in range(1, M):
    dp[0][y] = dp[0][y-1] + mat[0][y]

for x in range(1, N):
    dp[x][0] = dp[x-1][0] + mat[x][0]

def calc(x, y):
    if not dp[x][y]==-1:
        return dp[x][y]
    dp[x][y] = mat[x][y] + calc(x, y-1)+calc(x-1,y)-calc(x-1,y-1)
    return dp[x][y]

Q = int(input())

for _ in range(Q):
    X, Y = (int(x) for x in input().split())
    print(calc(X-1, Y-1))
