class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int n = tickets.length;
        int target = tickets[k];
        int totalCount = target * n;
        for(int ticket: tickets) {
            if(ticket < target) {
                totalCount -= (target - ticket);
            }
        }
        for(int i = k+1; i<n; i++) {
            if(tickets[i] >= target) {
                totalCount--;
            }
        }
       
        return totalCount;
    }
}
