class Solution {
    public int minIncrementForUnique(int[] nums) {
        Arrays.sort(nums);
        int count = 0;
        int n = nums.length;
        for(int i=1; i<n; i++) {
            if(nums[i-1] >= nums[i]) {
                int increment = nums[i-1] - nums[i] + 1;
                nums[i] = nums[i] + increment;
                count += increment;
            }
        }
        return count;
    }
}
