import java.util.HashSet;
import java.util.Collections;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int k = 0;
        Arrays.sort(nums);
        int n = nums.length;
        List<List<Integer>> result = new ArrayList();

        for(int i=0; i<n; i++) {
            if(nums[i] > 0) {
                break;
            }
            if(i!=0 && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i+1;
            int right = n -1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == k ){
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    int low = nums[left];
                    int high = nums[right];
                    while(left<right && nums[left] == low ) {
                        left+=1;
                    }
                    while(left<right && nums[right] == high ) {
                        right-=1;
                    }

                } else if(sum < k){
                    left+=1;
                } else{
                    right-=1;
                }

            }
        }
        return result;
    }
}