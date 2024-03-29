public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head.next == null) {
            return head.next;
        }
        ListNode slowP = head;
        ListNode fastP = head;
        for(int i=0; i<n; i++) {
            fastP = fastP.next;
        }
        boolean prematureEnd = false;
        if(fastP != null) {
            prematureEnd = true;
            fastP = fastP.next;
        }
        while(fastP!=null) {
            fastP = fastP.next;
            slowP = slowP.next;
        }
        if(!prematureEnd) {
            return head.next;
        }
        ListNode toDel = slowP.next;
        if(toDel!=null) {
            slowP.next = toDel.next; 
        }
        return head;
    }
}