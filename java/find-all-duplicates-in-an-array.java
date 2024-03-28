class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        int n = nums.length;
        int i=0;
        while(i<n) {
            int toPlace = nums[i] - 1;
            if(nums[toPlace]!=nums[i]) {
                int temp = nums[i];
                nums[i] = nums[toPlace];
                nums[toPlace] = temp;
            } else{
                i+=1;
            }
        }
        List<Integer> result = new ArrayList<Integer>();
        for(i=0; i<n; i++) {
            if(nums[i]!=i+1) {
                result.add(nums[i]);
            }
        }
        return result;
    }
}