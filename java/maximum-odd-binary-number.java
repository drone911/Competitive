class Solution {
    public String maximumOddBinaryNumber(String s) {
        int n = s.length();
        int count = 0;
        for(int i=0; i<n; i++) {
            if(s.charAt(i) == '1') {
                count++;
            }
        }
        StringBuilder result = new StringBuilder();
        for(int i=0; i<n-1; i++) {
            if(count != 1) {
                result.append('1');
                count--;                
            } else {
                result.append('0');
            }
        }
        result.append('1');
        return result.toString();
    }
}