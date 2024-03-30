class Solution {
    public static HashMap<String, Integer> deepCopy(HashMap<String, Integer> map) {
        HashMap<String, Integer> mapCopy = new HashMap();
        for(HashMap.Entry<String, Integer> entry: map.entrySet()) {
            mapCopy.put(new String(entry.getKey()), new Integer(entry.getValue()));
        }
        return mapCopy;
    }
    public List<Integer> findSubstring(String s, String[] words) {
        int n = s.length();
        int nWords = words.length;
        int wordLength = words[0].length();
        if(nWords * words[0].length() > n) {
            return new ArrayList<Integer>();
        }
        HashMap<String, Integer> counter = new HashMap();
        Integer count;
        for(String w: words){
            count = counter.get(w);
            if(count == null) counter.put(w, 1);
            else counter.put(w, count + 1);
        }

        int start = 0;
        int end = wordLength-1;
        List<Integer> result = new ArrayList();

        while(end<n) {
            String sub = s.substring(start, end+1);
            count = counter.get(sub);
            if(count != null) {
                HashMap<String, Integer> counterCopy = deepCopy(counter);
                if(count == 1) {
                    counterCopy.remove(sub);
                } else{
                    counterCopy.put(sub, count - 1);
                }
                int tempStart = start+wordLength;
                int tempEnd = end+wordLength;
                while(tempEnd < n) {
                    String tempSub = s.substring(tempStart, tempEnd+1);
                    count = counterCopy.get(tempSub);
                    if(count == null) {
                        break;
                    }
                    if(count == 1) {
                        counterCopy.remove(tempSub);
                    } else{
                        counterCopy.put(tempSub, count - 1);
                    }
                    tempEnd+=wordLength;
                    tempStart+=wordLength;
                }
                if(counterCopy.isEmpty()){
                    result.add(start);
                }
            }
            end+=1;
            start+=1;
        }
        return result;
    }
}