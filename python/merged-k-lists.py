# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        mergedListHead = ListNode()
        mergedListCurr = mergedListHead
        while True:
            nextNode = None
            index = None
            for i, curr in enumerate(lists):
                if not nextNode:
                    nextNode = curr
                    index = i
                else:
                    if curr and curr.val < nextNode.val:
                        nextNode = curr
                        index = i
            if nextNode:
                mergedListCurr.next = ListNode(nextNode.val)
                mergedListCurr = mergedListCurr.next
                lists[index] = lists[index].next
            else:
                break
        return mergedListHead.next