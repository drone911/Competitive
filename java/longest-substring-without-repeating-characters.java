class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        HashSet<Character> charSet = new HashSet();
        int left = 0;
        int right = 0;
        int maxLength = 0;
        while(right < n) {
            char currChar = s.charAt(right);
            if(!charSet.contains(currChar)) {
                int length = right - left + 1;
                if(maxLength < length) {
                    maxLength = length;
                }
            } else {
                while(left < right && charSet.contains(currChar)) {
                    charSet.remove(s.charAt(left));
                    left++;
                }
            }
            charSet.add(currChar);
            right++;
        }
        return maxLength;
    }
}