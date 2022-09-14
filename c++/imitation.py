question = set(input().split())
ans1 = input().split()
ans2 = input().split()

pcm1 = 0
pcm2 = 0
for word in ans1:
    if word in question:
        pcm1+=1
for word in ans2:
    if word in question:
        pcm2+=1

pcm1 = pcm1/len(ans1)
pcm2 = pcm2/len(ans2)

if pcm1>pcm2:
    print("NUMBER TWO IS THE HUMAN")
else:
    print("NUMBER ONE IS THE HUMAN")
