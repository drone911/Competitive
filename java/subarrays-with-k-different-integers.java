class Solution {
    public int subarraysWithAtmostKDistinctElements(int[] nums, int k) {
        if(k==0) {
            return 0;
        }
        int left = 0;
        int right = 0;
        int n = nums.length;
        int result = 0;
        HashMap<Integer, Integer> frequency = new HashMap();
        while(right < n) {
            frequency.merge(nums[right], 1, Integer::sum);
            if(frequency.size() <= k) {
                result += right - left + 1;
            } else {
                while(left<right && frequency.size() > k) {
                    Integer count = frequency.get(nums[left]);
                    if(count == 1) {
                        frequency.remove(nums[left]);
                    } else {
                        frequency.put(nums[left], count - 1);
                    }
                    left++;
                }
                result+=right-left+1;
            }
            right++;
        }
        return result;
    }
    public int subarraysWithKDistinct(int[] nums, int k) {
        if(nums.length < k) {
            return 0;
        }
        int subarrayWithAtmostKDistinct = subarraysWithAtmostKDistinctElements(nums, k);
        int subarrayWithAtmostKMinsOneDistinct = subarraysWithAtmostKDistinctElements(nums, k-1);
        return subarrayWithAtmostKDistinct - subarrayWithAtmostKMinsOneDistinct;
    }
}
