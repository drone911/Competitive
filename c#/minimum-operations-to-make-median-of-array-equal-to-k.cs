public class Solution {
    public long MinOperationsToMakeMedianK(int[] nums, int k) {
        int n = nums.Length;
        _mergeSort(nums, 0, n-1);
        int medianIndex = (int)Math.Ceiling((float)(n-1)/2);
        Console.WriteLine(medianIndex);
        int median = nums[medianIndex];
        if(median == k) {
            return 0;
        } else {
            long minOperations = 0;
            if(median < k) {
                while(medianIndex < n && nums[medianIndex] < k) {
                    minOperations += k - nums[medianIndex];
                    medianIndex++;
                }
            } else {
                while(medianIndex >= 0 && nums[medianIndex] > k) {
                    minOperations += nums[medianIndex] - k;
                    medianIndex--;
                }
            }
            return minOperations;
        }
    }
    private void _mergeSort(int[] nums, int l, int r) {
        if(l>=r) {
            return;
        }
        int mid = l + (r-l)/2;
        _mergeSort(nums, l, mid);
        _mergeSort(nums, mid+1, r);
        int n = r-l+1;
        int[] merged = new int[n];
        int iterLow = l;
        int iterHigh = mid+1;
        int iterMerged = 0;
        while(iterLow <= mid && iterHigh <= r) {
            if(nums[iterLow] < nums[iterHigh]) {
                merged[iterMerged] = nums[iterLow];
                iterLow++;
            } else {
                merged[iterMerged] = nums[iterHigh];
                iterHigh++;
            }
            iterMerged++;
        }
        while(iterLow <= mid) {
            merged[iterMerged] = nums[iterLow];
            iterLow++;
            iterMerged++;
        }
        while(iterHigh <= r) {
            merged[iterMerged] = nums[iterHigh];
            iterHigh++;
            iterMerged++;
        }
        for(int i=0; i<n; i++) {
            nums[l+i] = merged[i];
        }
    }
}
