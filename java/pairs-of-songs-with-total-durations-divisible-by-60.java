class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int n = time.length;
        int result = 0;
        int[] exists = new int[501];
        for(int i=0; i<n; i++) {
            int element = time[i];
            int diff = ((int)Math.ceil((double)element/60)) * 60 - element;
            while(diff <= 500) {
                result+=exists[diff];    
                diff+=60;
            }
            exists[element] += 1;
         }
        return result;
    }
}
