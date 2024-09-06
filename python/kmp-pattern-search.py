def generateLPS(pat):
    lps = [0] * m

    i = 1
    len = 0
    while i<m:
        if pat[i] == pat[len]:
            len+=1
            lps[i] = len
            i+=1
        else:
            if len!=0:
                len = lps[len-1]
            else:
                i+=1
                lps[i] = 0
            

def search(pat, txt):
    n = len(txt)
    m = len(pat)

    lps = generateLPS(pat, m)

    i=0
    j=0
    while n-i >= m-j:
        if txt[i] == pat[j]:
            i+=1
            j+=1
        
        if j==M:
            print("Found")
            j = lps[j-1]
        elif i<n and pat[j]!=txt[i]:
            if j!=0:
                j = lps[j-1]
            else:
                i+=1