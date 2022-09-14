from numpy import ma


T = int(input())

def solve(N: int, input_set: list):
    compounded = []
    curr_sum = 0

    for i, x in enumerate(input_set):
        curr_sum=(curr_sum+x) % N
        if curr_sum == 0:
            print(i+1)
            print(" ".join(map(str, range(1, i+2))))
            return
        compounded.append((curr_sum, i+1))
    compounded = sorted(compounded)
    prev_x = -1
    prev_y = None
    for x, y in compounded:
        if x == prev_x:
            print(y-prev_y)
            print(" ".join(map(str, range(prev_y+1, y+1))))
            return
        prev_x = x
        prev_y = y
    raise ValueError("Did not find matching moduli")

for _ in range(T):
    N = int(input())
    input_set = [int(x) for x in  input().split()]
    solve(N, input_set)