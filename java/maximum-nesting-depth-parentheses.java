class Solution {
    public int maxDepth(String s) {
        int maxCount = 0;
        int count = 0;
        int i = 0;
        int n = s.length();
        while(i < n){
            char ch = s.charAt(i);
            if(ch == '(') {
                count++;
            } else if(ch == ')'){
                count--;
            }
            if(count > maxCount) {
                maxCount = count;
            }
            i+=1;
        }
        return maxCount;
    }
}