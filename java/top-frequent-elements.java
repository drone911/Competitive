class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> frequency = new HashMap();
        for(int num: nums) {
            frequency.merge(num, 1, Integer::sum);        
        }
        ArrayList<HashMap.Entry<Integer, Integer>> result = new ArrayList();
        for(HashMap.Entry<Integer, Integer> entry: frequency.entrySet()) {
            result.add(entry);
        }
        Comparator<HashMap.Entry<Integer, Integer>> compareByValue = new Comparator<HashMap.Entry<Integer, Integer>>() {
            @Override
            public int compare(HashMap.Entry<Integer, Integer> o1, HashMap.Entry<Integer, Integer> o2) {
                return o1.getValue().compareTo(o2.getValue());
            }
        };
        Collections.sort(result, compareByValue);
        int n = result.size();
        return result.subList(n-k, n).stream().mapToInt(i -> i.getKey()).toArray();
    }
}