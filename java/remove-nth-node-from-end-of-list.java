public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
 
class Solution {
    ListNode result = null;
    public int removeNthFromEndUtil(ListNode head, int n) {
        if(head==null) {
            return n;
        }
        int pos = removeNthFromEndUtil(head.next, n);
        if(pos==0) {
            this.result = head.next;
            if(this.result != null) {
                head.next = this.result.next;
                this.result.next = null;
            }
        }
        return pos-1;
    }
    public ListNode removeNthFromEnd(ListNode head, int n) {
        removeNthFromEndUtil(head, n);
        if(this.result == null) {
            return head.next;
        }
        return head;
    }
}