def computerLPS(pat, m):
    lps = [0] * m
    i=1
    len=0
    while i<m:
        if pat[len] == pat[i]:
            len+=1
            lps[i] = len
            i+=1
        else:
            if len==0:
                i+=1
            else:
                len = lps[len-1]
    return lps

def search(txt, pat):
    m = len(pat)
    n = len(txt)

    lps = computerLPS(pat, m)

    i = 0
    j=0
    while n-i >= m-j:
        if pat[j] == txt[i]:
            i+=1
            j+=1
        
        if j==M:
            return j
            j = lps[j-1]
        elif i<n and pat[j]!=txt[i]:
            if j==0:
                i+=1
            else:
                j = lps[j-1]
