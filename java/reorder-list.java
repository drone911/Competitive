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
    public void reorderList(ListNode head) {
        Stack<ListNode> toReverse = new Stack();
        ListNode current = head;
        while(current != null) {
            toReverse.push(current);
            current = current.next;
        }
        current = head;
        ListNode currentRev = toReverse.pop();
        while(current.next != currentRev && current != currentRev) {
            currentRev.next = current.next;
            ListNode temp = current.next;
            current.next = currentRev;
            current = temp;
            if(!toReverse.empty()) {
                currentRev = toReverse.pop();
            }
        }
        currentRev.next = null;
    }
}
