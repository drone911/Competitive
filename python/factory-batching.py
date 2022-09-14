from math import sqrt
N = int(input())
for i in range(2, int(sqrt(N))+1):
    if N%i==0:
        print(f"{i} {N-i}")
        break
print(f"{1} {N-1}")
