# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
        
    def serialize(self, root: Optional[TreeNode]) -> str:
        """Encodes a tree to a single string.
        """
        result = ""
        if not root:
            return result
        remainingNodes = [root]
        
        result+=str(root.val) + ","
        while len(remainingNodes)>0:
            curr = remainingNodes.pop(0)
            
            if curr.left:
                result+=str(curr.left.val)+","
                remainingNodes.append(curr.left)
            else:
                result+="null,"
            if curr.right:
                result+=str(curr.right.val)+","
                remainingNodes.append(curr.right)
            else:
                result+="null,"
        return result.rstrip(",")

    def deserializeUtil(self, root, data, index):
        if index >= len(data):
            return root
        if data[index] == "null":
            return None
        
        root = TreeNode(int(data[index]))
        root.left = self.deserializeUtil(root.left, data, index*2+1)
        root.right = self.deserializeUtil(root.right, data, index*2+2)
        return root

        
    def deserialize(self, data: str) -> Optional[TreeNode]:
        """Decodes your encoded data to tree.
        """
        if data == '':
            return None
        data = data.split(",")
        root = self.deserializeUtil(None, data, 0)
        return root

            

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans