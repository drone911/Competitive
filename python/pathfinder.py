N = int(input())
next_move = [("+", "Y"), ("+", "X"), ("-", "Y"), ("-", "X")]
X = 0
Y = 0

point = 0

for _ in range(N):
    move = input().split()
    if move[0] == "L":
        point -= 1
        point = point % 4
    elif move[0] == 'R':
        point +=1
        point = point%4
    else:
        if next_move[point][0]== '+':
            if next_move[point][1] == 'X':
                X +=int(move[1])
            else:
                Y +=int(move[1])
        else:
            if next_move[point][1] == 'X':
                X -=int(move[1])
            else:
                Y -=int(move[1])
print(f"{X} {Y}")