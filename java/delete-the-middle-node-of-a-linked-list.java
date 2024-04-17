/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteMiddle(ListNode head) {
        ListNode pseudoHead = new ListNode(-1, head);
        ListNode prev = pseudoHead;
        ListNode slow = head;
        ListNode fast = head;
        while(fast != null) {
            fast = fast.next;
            if(fast != null) {
                fast = fast.next;
            } else {
                break;
            }
            prev = slow;
            slow = slow.next;
        }
        prev.next = slow == null? null : slow.next;
        return pseudoHead.next;
    }
}
