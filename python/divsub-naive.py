from functools import reduce


T = int(input())

def solve_naive(N: int, input_set: list, to_sum: list):
    if to_sum:
        sum = reduce(lambda x, y: x+y, [y for _, y in to_sum])
        if sum % N == 0:
            return to_sum 

    if not input_set:
        return False
    
    return solve_naive(N, input_set[:-1], to_sum) or solve_naive(N, input_set[:-1], to_sum + [(len(input_set) ,input_set[-1])])

for _ in range(T):
    N = int(input())
    input_set = [int(x) for x in input().split()]
    to_sum = solve_naive(N, input_set, [])
    print(len(to_sum))
    print(" ".join(sorted([str(x) for x, _ in to_sum])))