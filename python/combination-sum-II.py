class Solution:
    def combinationSum2Util(self, candidates: list[int], target: int, index: int, current: list[int], sum: int, result: set) -> list[list[int]]:
        if index == len(candidates):
            return
        for i in range(index, len(candidates)):
            if i > index and candidates[i] == candidates[i-1]:
                continue
            sum+=candidates[i]
            current.append(candidates[i])
            print(current)
            if sum==target:
                result.add(tuple(sorted(current)))
            elif sum<target:
                self.combinationSum2Util(candidates, target, i+1, current, sum, result)
            sum-=candidates[i]
            current.pop()

    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
        current = []
        result = set()
        index = 0
        sum = 0
        self.combinationSum2Util(sorted(candidates), target, index, current, sum, result)
        return result
    
print(Solution().combinationSum2([1, 1, 1, 1, 1, 1,1 , 1, 1, 1, 1, 1, 1, 1, 1, 1], 8))
                    