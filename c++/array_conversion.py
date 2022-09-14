T = int(input())

def backtrack(cache, arr, N, K, i, summ):
    if i==N:
        if summ==K:
            return True
        else:
            return False
    res = False
    if cache[i].get(summ+arr[i]) is None:
        cache[i][summ+arr[i]] = backtrack(cache, arr, N, K, i+1, summ+arr[i])
        res = res or cache[i][summ+arr[i]]
    
    if cache[i].get(summ-arr[i]) is None:
        cache[i][summ-arr[i]] = backtrack(cache, arr, N, K, i+1, summ-arr[i])
        res = res or cache[i][summ-arr[i]]
    
    if cache[i].get(summ+arr[i]+i) is None:
        cache[i][summ+arr[i]+i] = backtrack(cache, arr, N, K, i+1, summ+arr[i]+i)
        res = res or cache[i][summ+arr[i]+i]
    
    if cache[i].get(summ+arr[i]-i) is None:
        cache[i][summ+arr[i]-i] = backtrack(cache, arr, N, K, i+1, summ+arr[i]-i)
        res = res or cache[i][summ+arr[i]-i]
    return res

for _ in range(T):
    N, K = (int(x) for x in input().split())
    arr = [int(x) for x in input().split()]
    cache = [{} for x in range(N)]
    print("YES" if backtrack(cache, arr, N, K, 0, 0) else "NO")