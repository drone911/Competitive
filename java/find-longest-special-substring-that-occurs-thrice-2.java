class Solution {
    public int maximumLength(String s) {
        int n = s.length();
        int[] specialStringLength = new int[n];
        char prevCh = s.charAt(0);
        HashMap<Character, PriorityQueue<Integer>> result = new HashMap();

        PriorityQueue<Integer> tempQueue = new PriorityQueue(3);
        tempQueue.add(1);
        result.put(prevCh, tempQueue);

        int length = 1;
        int maxLength = 0;
        for(int i=1; i<n; i++) {
            char ch = s.charAt(i);
            if(ch == prevCh) {
                length = length + 1;
            } else{
                length = 1;
            }
            prevCh = ch;
            PriorityQueue<Integer> queue = result.get(ch);
            if(queue == null) {
                queue = new PriorityQueue(3);
            }
            queue.add(length);
            if(queue.size() > 3) {
                queue.poll();
            }
            if(queue.size() == 3) {
                maxLength = Math.max(maxLength, queue.peek());
            }
            result.put(ch, queue);
        }
        return maxLength==0? -1:maxLength;
    }
}