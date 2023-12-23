# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        small_chain_start = ListNode()
        big_chain_start = ListNode()
        
        small_chain_end = small_chain_start
        big_chain_end = big_chain_start
        
        curr = head
        while curr:
            if curr.val < x:
                small_chain_end.next = curr
                curr = curr.next
                small_chain_end = small_chain_end.next
                small_chain_end.next = None
            else:
                big_chain_end.next = curr
                curr = curr.next
                big_chain_end = big_chain_end.next
                big_chain_end.next = None
        
        small_chain_end.next = big_chain_start.next
        return small_chain_start.next