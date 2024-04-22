class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int currProd = 1;
        int result = -10;
        for(int i=0; i<n; i++) {
            currProd = currProd * nums[i];
            if(currProd > result) {
                result = currProd;
            }
            if(currProd == 0) {
                currProd = 1;
            }
        }
        currProd = 1;

        for(int i=n-1; i>=0; i--) {
            currProd = currProd * nums[i];
            if(currProd > result) {
                result = currProd;
            }
            if(currProd == 0) {
                currProd = 1;
            }
        }
        return result;
    }
}
