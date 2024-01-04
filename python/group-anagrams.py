class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        results = {}
        for s in strs:
            sorted_s = str(sorted(s))
            val = results.get(sorted_s)
            if val:
                val.append(s)
            else:
                results[sorted_s] = [s]
        return [val for val in results.values()]