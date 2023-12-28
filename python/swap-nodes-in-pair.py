# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swap(node1, node2):
        node1.next = node2.next
        node2.next = node1
        return node2, node1

    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        curr = head
        toReturn = head.next
        while True:
            node2, node1 = Solution.swap(curr, curr.next)
            curr = node1.next
            if curr and curr.next:
                node1.next = curr.next
            elif curr:
                node1.next = curr
                break
            else:
                break
        return toReturn