class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int n = nums.length;
        int[] cumSum = new int[n];
        cumSum[0] = nums[0];
        for(int i=1; i<n; i++) {
            cumSum[i] = nums[i] + cumSum[i-1];
        }
        HashMap<Integer, Integer> lastSeen = new HashMap();
        int left = -1;
        int right = 0;
        int maxSum = 0;
        while(right < n) {
            int num = nums[right];
            Integer numLastIndex = lastSeen.get(num);
            if(numLastIndex != null) {
                left = Math.max(left, numLastIndex);
            }
            int sum;
            if(left != -1) {
                sum = cumSum[right] - cumSum[left];
            } else{
                sum = cumSum[right];
            }
            if(sum > maxSum) {
                maxSum = sum;
            }
            lastSeen.put(num, right);
            right++;
        }
        return maxSum;
    }
}