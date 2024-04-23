class LinkNode {
    int value;
    HashSet strings;
    LinkNode next;
    LinkNode prev;
    LinkNode(int val) {
        value = val;
        strings = new HashSet();
    }
}
class AllOne {
    private LinkNode front;
    private LinkNode back;
    HashMap<String, LinkNode> countMap;
    public AllOne() {
        countMap = new HashMap();
    }
    
    public void inc(String key) {
        LinkNode countNode = countMap.get(key);
        if(countNode != null) {
            LinkNode nextNode = countNode.next;
            if(nextNode == null) {
                nextNode = new LinkNode(countNode.value + 1);
                back = nextNode;
                nextNode.prev = countNode;
                countNode.next = nextNode;
                countNode.strings.remove(key);
                nextNode.strings.add(key);
            } else {
                if(nextNode.value != countNode.value + 1) {
                    nextNode = new LinkNode(countNode.value + 1);
                    countNode.next.prev = nextNode;
                    nextNode.prev = countNode;
                    nextNode.next = countNode.next;
                    countNode.next = nextNode;
                }
                countNode.strings.remove(key);
                nextNode.strings.add(key);
            }
            checkAndDelete(countNode);
            countMap.put(key, nextNode);
        } else {
            if(front == null) {
                front = new LinkNode(1);
                back = front;
                front.strings.add(key);
            } else if(front.value != 1) {
                LinkNode newNode = new LinkNode(1);
                newNode.next = front;
                front.prev = newNode;
                front = newNode;
            }
            front.strings.add(key);
            countMap.put(key, front);
        }
    }
    void checkAndDelete(LinkNode node) {
        if(node.strings.size() != 0) {
            return;
        }
        if(front == node && back == node) {
            front = null;
            back = null;
        } else if(front == node) {
            front = front.next;
            node.next = null;
            front.prev = null;
        } else if(back == node) {
            back = back.prev;
            back.next = null;
            node.prev = null;
        } else {
            node.prev.next = node.next;
            node.next.prev = node.prev;
            node.next = null;
            node.prev = null;
        }
    }
    public void dec(String key) {
        LinkNode countNode = countMap.get(key);
        if(countNode.value > 1) {
            LinkNode prevNode = countNode.prev;
            if(prevNode == null) {
                prevNode = new LinkNode(countNode.value - 1);
                front = prevNode;
                prevNode.next = countNode;
                countNode.prev = prevNode;
                countNode.strings.remove(key);
                prevNode.strings.add(key);
            } else {
                if(prevNode.value != countNode.value - 1) {
                    prevNode = new LinkNode(countNode.value - 1);
                    countNode.prev.next = prevNode;
                    prevNode.next = countNode;
                    prevNode.prev = countNode.prev;
                    countNode.prev = prevNode;
                }
                countNode.strings.remove(key);
                prevNode.strings.add(key);
            }
            checkAndDelete(countNode);
            countMap.put(key, prevNode);
        } else {
            countMap.remove(key);
            countNode.strings.remove(key);
            checkAndDelete(countNode);
        }
    }
    
    public String getMaxKey() {
        if(back == null) {
            return "";
        } else {
            return (String)back.strings.iterator().next();
        }
    }
    
    public String getMinKey() {
        if(front == null) {
            return "";
        } else {
            return (String)front.strings.iterator().next();
        }
        
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */
