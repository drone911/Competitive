class Solution {
    public int partition(int[] nums, int left, int right, int k) {
        int start = left;
        left++;
        int end = right;
        while(left<=right) {
            while(left <= end && nums[left] < nums[start]) {
                left++;
            }
            while(right > start && nums[right] >= nums[start]) {
                right--;
            }
            if(left<right) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++;
                right--;
            }
        }
        int temp = nums[right];
        nums[right] = nums[start];
        nums[start] = temp;
        return right;
    }
    public int findKthLargestUtil(int[] nums, int left, int right, int k) {
        int partitionIndex = partition(nums, left, right, k);
        int rank = right - partitionIndex + 1;
        // System.out.print(left);
        // System.out.print("   ");
        // System.out.print(right);
        // System.out.println();
        
        if(rank == k) {
            return nums[partitionIndex];
        } else if(rank > k) {
            return findKthLargestUtil(nums, partitionIndex + 1, right, k);
        } else {
            return findKthLargestUtil(nums, left, partitionIndex - 1, k - rank);
        }
    }
    public int findKthLargest(int[] nums, int k) {
        return findKthLargestUtil(nums, 0, nums.length-1, k);
    }
}