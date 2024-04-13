class Solution {
    public int partitionString(String s) {
        int n = s.length();
        int[] prevIndex = new int[n]; 
        int[] lastSeenIndex = new int[26];
        for(int i=0; i<26; i++) {
            lastSeenIndex[i] = -1;
        }
        for(int i=0; i<n; i++) {
            char c = s.charAt(i);
            prevIndex[i] = lastSeenIndex[(int)c % 26];
            lastSeenIndex[(int)c % 26] = i;
        }
        int i = n-1;
        int result = 1;
        int stop = prevIndex[i] == -1? -1 : prevIndex[i];
        while(i>=0) {
            if(i == stop) {
                stop = prevIndex[i];
                result++;
            }
            if(prevIndex[i] == -1) {
                i--;
                continue;
            }

            if(stop < prevIndex[i]) {
                stop = prevIndex[i];
            }
            i--;
        }
        return result;
    }
}