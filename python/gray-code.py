class Solution:

    def reverse(self, arr, start, end):
        while start<end:
            arr[start], arr[end] = arr[end], arr[start]
            start+=1
            end-=1
    def grayCodeUtil(self, result, start, end):
        if start >= end:
            return
        
        mid = (start+end)//2

        self.grayCodeUtil(result, start, mid)
        self.grayCodeUtil(result, mid+1, end)

        self.reverse(result, mid+1, end)


    def grayCode(self, n: int) -> List[int]:
        start = 0
        end = 2**n - 1
        result = [i for i in range(end+1)]
        self.grayCodeUtil(result, start, end)
        return result