class Solution:
    def myAtoi(self, s: str) -> int:
        i = 0
        negative = False
        res = 0
        started = False
        phase = 0
        MIN = -2**31
        MAX = 2**31 - 1
        for char in s:
            if phase == 0:
                if char == '-':
                    negative = True
                    phase+=1
                    continue
                if char == '+':
                    phase+=1
                    continue
                if char.isdigit():
                    res = int(char)
                    if negative:
                        res*=-1
                    phase+=2
                    continue
                if char != ' ':
                    break
            elif phase == 1:
                if char.isdigit():
                    res = int(char)
                    if negative:
                        res*=-1
                    phase+=1
                else:
                    break
            elif phase == 2:
                if char.isdigit():
                    temp = res * 10
                    if negative:
                        temp-=int(char)
                        if temp > MIN :
                            res = temp
                        else:
                            res = MIN
                    else:
                        temp+=int(char)
                        if temp < MAX:
                            res = temp
                        else:
                            res = MAX
                else:
                    break
        return res
