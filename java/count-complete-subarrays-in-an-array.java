class Solution {
    public int countAtMostKDistictSubarrays(int[] nums, int k) {
        if(k == 0) {
            return 0;
        }
        int left = 0;
        int right = 0;
        int n = nums.length;
        int result = 0;
        HashMap<Integer, Integer> frequency = new HashMap();
        while(right < n) {
            int num = nums[right];
            frequency.merge(num, 1, Integer::sum);
            if(frequency.size() > k) {
                while(frequency.size()>k && left<right) {
                    int toDecrease = nums[left]; 
                    Integer count = frequency.get(toDecrease);
                    if(count == 1) {
                        frequency.remove(toDecrease);
                    } else {
                        frequency.put(toDecrease, count-1);
                    }
                    left++;
                }
            }
            result += right - left + 1;
            right++;
        }
        return result;
    }
    public int countCompleteSubarrays(int[] nums) {
        HashSet<Integer> numSet = new HashSet();
        for(int num: nums) {
            numSet.add(num);
        }
        int k = numSet.size();
        return (countAtMostKDistictSubarrays(nums, k) - countAtMostKDistictSubarrays(nums, k-1));
    }
}