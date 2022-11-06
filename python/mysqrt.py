def mySqrt(x: int) -> int:
    left, right = 0, x
    while left < right:
        mid = left + (right - left) // 2
        if mid * mid <= x:
            left = mid + 1
        else:
            right = mid
    return left - 1

def mysqrt(n: int):
    l = 0
    r = n
    while l<r:
        m = l + (r-l)//2
        if m*m<=n:
            l = m+1
        else:
            r = m
    return l


print(mysqrt(1))
print(mysqrt(2))
print(mysqrt(0))