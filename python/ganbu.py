import sys
FILE_INPUT = 1
input_fd  = None
if FILE_INPUT:
    input_fd = open("ganbu-input.txt")
    sys.stdin = input_fd

def calc_effective_weights(graph, i, A, visited, effective_weights):
    effective_weights[i] = A[i]
    for u, _ in graph[i]:
        sub_graph_sum = calc_effective_weights(graph, u-1, A, visited, effective_weights)
        effective_weights[i] += sub_graph_sum
    return effective_weights[i]    


def find_additional_sum(graph, i, removed_edges_count, to_remove, A, effective_weights):
    if removed_edges_count<to_remove:
        additional_sum = 0
        for u, special in graph[i]:
            if special or not_to_add:
                additional_sum += find_additional_sum(graph, u-1, removed_edges_count, to_remove, effective_weights)
            else:
                additional_sum += effective_weights[u-1]
                

        return additional_sum
    else:
        return 0
        
def add_special_edge(graph, u, v):
    for i in range(len(graph[u-1])):
        if graph[u-1][i][0] == v:
            graph[u-1][i][1] = 1
    
    #for i in range(len(graph[v-1])):
    #    if graph[v-1][i][0] == u:
    #        graph[v-1][i][1] = 1

def remove_special_edge(graph, u, v):
    for i in range(len(graph[u-1])):
        if graph[u-1][i][0] == v:
            graph[u-1][i][1] = 0
    
    #for i in range(len(graph[v-1])):
    #    if graph[v-1][i][0] == u:
    #        graph[v-1][i][1] = 0


T = int(input())
N, Q = map(int, input().split())
graph = [[] for _ in range(N)]
parents = map(int, input().split())

for i, parent in enumerate(parents):
    graph[parent-1].append([i+2, 0])
    # graph[i+1].append([parent, 0])

A = list(map(int, input().split()))

effective_weights = [0 for _ in range(N)]
visited = [False for _ in range(N)]

calc_effective_weights(graph, 0, A, visited, effective_weights)

print(f"Nodes:                  {list(range(1, N+1))}")
print(f"Weights                 {A}")
print("Effective Weights:      " +   str(effective_weights))

N_S = int(input())
for _ in range(N_S):
    u, v = list(map(int, input().split()))
    add_special_edge(graph, u, v)

print(f"graph: {graph}")

for _ in range(Q):
    control, in_one, in_two = list(map(int, input().split()))
    if control == 1:
        visited = [False for _ in range(N)]

        sum, removed_edges_count = find_max_sum(graph, in_one, visited, 0, in_two-1, A, effective_weights)
        if removed_edges_count==in_two:
            print(sum)
        else:
            print("IMPOSSIBLE")
    elif control == 2:
        add_special_edge(graph, in_one, in_two)
    else:
        remove_special_edge(graph, in_one, in_two)

if input_fd:
    input_fd.close()