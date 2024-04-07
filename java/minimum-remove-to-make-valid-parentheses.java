class Solution {
    public String minRemoveToMakeValid(String s) {
        int n = s.length();
        int count = 0;
        StringBuilder resultForwardPass = new StringBuilder();
        for(int i=0; i<n; i++) {
            char character = s.charAt(i);
            if(character == '(') {
                count++;
                resultForwardPass.append(character);
            } else if(character == ')') {
                if(count != 0) {
                    resultForwardPass.append(character);
                    count--;
                }
            } else{
                resultForwardPass.append(character);
            }
        }
        count = 0;
        n = resultForwardPass.length();
        StringBuilder resultBackwardPass = new StringBuilder();
        for(int i=n-1; i>=0; i--) {
            char character = resultForwardPass.charAt(i);
            if(character == ')') {
                count++;
                resultBackwardPass.append(character);
            } else if(character == '(') {
                if(count != 0) {
                    resultBackwardPass.append(character);
                    count--;
                }
            } else{
                resultBackwardPass.append(character);
            }
        }
        resultBackwardPass.reverse();
        return resultBackwardPass.toString();
    }
}