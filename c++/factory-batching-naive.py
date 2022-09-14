N = int(input())

def gcd(a, b):
    if b==0:
        return a
    else:
        return gcd(b, a%b)

max_hcf = 1
k = 1
for i in range(1, N//2+1):
    hcf = gcd(i, N-i)
    if hcf>max_hcf:
        max_hcf = hcf
        k = i
print(f"{k} {N-k}")
