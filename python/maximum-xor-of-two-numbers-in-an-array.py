class Node:
    def __init__(self, left = None, right = None):
        self.left = left
        self.right = right

class Trie:
    def __init__(self):
        self.root = Node()
        pass

    def insert(self, val):
        curr = self.root

        for i in range(31, -1, -1):
            bit = (val >> i) & 1
            if bit == 1:
                if curr.right == None:
                    curr.right = Node()
                curr = curr.right
            else:
                if curr.left == None:
                    curr.left = Node()
                curr = curr.left
    def findOpp(self, val):
        curr = self.root
        opp = 0
        for i in range(31, -1, -1):
            bit = (val >> i) & 1
            if bit == 1:
                if curr.left:
                    curr = curr.left
                else:
                    opp = (1 << i)  | opp
                    curr = curr.right
            else:
                if curr.right:
                    opp = (1 << i)  | opp
                    curr = curr.right
                else:
                    curr = curr.left
        return opp

            

class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        trie = Trie()
        result = 0
        trie.insert(nums[0])
        for num in nums[1:]:
            result = max(result, num ^ trie.findOpp(num))
            trie.insert(num)
        return result

class Solution2:
    def findMaximumXOR(self, nums: List[int]) -> int:
        maxLen = len(bin(max(nums))) - 2
        maxXor = 0
        for i in range(maxLen-1, -1, -1):
            maxXor <<= 1
            currXor = maxXor | 1
            prefixes = set([num >> i for num in nums])
            maxXor |= any([currXor ^ prefix in prefixes for prefix in prefixes])
        return maxXor