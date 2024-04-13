class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int n = arr.length;
        if(x <= arr[0]) {
            return Arrays.stream(Arrays.copyOfRange(arr, 0, k)).boxed().collect(Collectors.toList());
        }
        if(x>=arr[n-1]) {
            return Arrays.stream(Arrays.copyOfRange(arr, n-k, n)).boxed().collect(Collectors.toList());
        }
        int left = 0;
        int right = k-1;
        int resultLeft = left;
        int resultRight = right;
        int minDiff = 0;
        for(int i=left; i<=right; i++) {
            minDiff += Math.abs(x-arr[i]);
        }
        left++;
        right++;
        int runningDiff = minDiff;
        while(right<n) {
            runningDiff -= Math.abs(x-arr[left-1]);
            runningDiff += Math.abs(x-arr[right]);
            if(minDiff > runningDiff) {
                minDiff = runningDiff;
                resultLeft = left;
                resultRight = right;
            }
            left++;
            right++;
        }
        return Arrays.stream(Arrays.copyOfRange(arr, resultLeft, resultRight+1)).boxed().collect(Collectors.toList());
    }
}