# Definition for a binary tree node.
from typing import Optional, List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pathSumUtil(self, root: Optional[TreeNode], targetSum: int, path: List[int], sum: int, result: List[List[int]]):
        if not root:
            return
        sum+=root.val
        path.append(root.val)

        if not root.left and not root.right:
            if targetSum == sum:
                result.append(path.copy())

        self.pathSumUtil(root.left, targetSum, path, sum, result)
        self.pathSumUtil(root.right, targetSum, path, sum, result)
        
        sum -= path.pop()


    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        sum = 0
        path = []
        result = []
        self.pathSumUtil(root, targetSum, path, sum, result)
        return result