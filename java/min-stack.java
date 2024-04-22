class LinkNode {
    public int value;
    public LinkNode next;
    public LinkNode minElementYet;
    LinkNode(int val) {
        value = val;
    }
}
class MinStack {
    private LinkNode root;

    public MinStack() {
    }
    
    public void push(int val) {
        LinkNode toAdd = new LinkNode(val);
        if(root == null) {
            toAdd.minElementYet = toAdd;
        } else{
            LinkNode minElement = root.minElementYet;
            if(minElement.value > val) {
                toAdd.minElementYet = toAdd;
            } else {
                toAdd.minElementYet = minElement;
            }
        }
        toAdd.next = root;
        root = toAdd;
    }
    
    public void pop() {
        root = root.next;
    }
    
    public int top() {
        return root.value;
    }
    
    public int getMin() {
        return root.minElementYet.value;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
