class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int n = nums.length;
        int prod = 1;
        int left = 0;
        int right = 0;
        int result = 0;
        while(right<n) {
            prod *= nums[right];
            if(prod < k) {
                result += right - left + 1;
            } else {
                while(left<right && prod>= k) {
                    prod /= nums[left];
                    left++;
                }
                if(prod>=k) {
                    prod = nums[right];
                } else{
                    result += right - left + 1;
                }
            }
            right++;
        }
        return result;
    }
}