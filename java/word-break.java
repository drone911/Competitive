class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        HashMap<String, Boolean> present = new HashMap();
        present.put("", true);
        int wordsLen = wordDict.size();
        for(String word: wordDict) {
            present.put(word, true);
        }
        int n = s.length();
        int start = 0;
        for(int i=1; i<n; i++) {
            for(String word: wordDict) {
                int wordLength = word.length();
                int end = i+1;
                int subStringLength = end - start;
                if(subStringLength < wordLength) {
                    continue;
                }
                String subString = s.substring(start, end);
                String left = subString.substring(0, subStringLength - wordLength);
                String right = subString.substring(subStringLength - wordLength);
                if(present.get(left) != null && present.get(right) != null) {
                    present.put(subString, true);
                    break;
                }
            }
        } 
        return present.get(s) == null ? false : true;
    }
}