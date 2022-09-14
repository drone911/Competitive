N = int(input())

caps = []
for _ in range(N):
    caps.append([int(x) for x in input().split()])

count = 0
def count_unique_combinations(level, current_set):
    for elem in caps[level]:
        if elem not in current_set:
            global count
            if level == N-1:
                count+=1
            else:
                current_set.add(elem)
                count_unique_combinations(level+1, current_set)
                current_set.remove(elem)

count_unique_combinations(0, set())

print(count)