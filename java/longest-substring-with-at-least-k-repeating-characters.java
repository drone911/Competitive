class Solution {
    public int longestSubstring(String s, int k) {
        int n = s.length();
        int[] frequency = new int[26];
        int maxUniqueCharacters = 0;
        for(int i=0; i<n; i++) {
            char ch = s.charAt(i);
            frequency[(int)ch%26]++;
            if(frequency[(int)ch%26] == k) {
                maxUniqueCharacters++;
            }
        }
        int result = 0;
        int uniqueCharacters = 1;
        while(uniqueCharacters <= maxUniqueCharacters) {
            for(int i=0; i<26; i++) {
                frequency[i] = 0;
            }
            int left = 0;
            int right = 0;
            int currUnique = 0;
            int currDistinctKCount = 0;
            while(right < n) {
                if(currUnique <= uniqueCharacters) {
                    char ch = s.charAt(right);
                    if(frequency[ch%26] == 0) {
                        currUnique++;
                    }
                    frequency[ch%26]++;
                    if(frequency[ch%26] == k) {
                        currDistinctKCount++;
                    }
                    if(currDistinctKCount >= uniqueCharacters && currUnique == uniqueCharacters) {
                        int length = right - left + 1;
                        if(result < length) {
                            result = length;
                        }
                    }
                    right++;
                } else {
                    char ch = s.charAt(left);
                    if(frequency[ch%26] == 1) {
                        currUnique--;
                    }
                    if(frequency[ch%26] == k) {
                        currDistinctKCount--;
                    }
                    frequency[ch%26]--;
                    left++;
                }
            }
            uniqueCharacters++;
        }
        return result;
    }
}
