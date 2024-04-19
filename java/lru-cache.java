class DoublyNode {
    int value;
    int key;
    DoublyNode prev;
    DoublyNode next;
    public DoublyNode(int key, int value, DoublyNode prev, DoublyNode next) {
        this.key = key;
        this.value = value;
        this.prev = prev;
        this.next = next;
    }
}
class DoublyLinkedList {
    public DoublyNode front = null;
    public DoublyNode back = null;

    public DoublyLinkedList() {
    }
    public DoublyNode pushBack(DoublyNode node) {
        if(front == null && back == null) {
            front = node;
            back = node;
        } else if(front == back) {
            node.prev = front;
            front.next = node;
            back = node;
        } else {
            back.next = node;
            node.prev = back;
            back = node;
        }
        return back;
    }
    public DoublyNode popFront() {
        if(front == null && back == null) {
            return null;
        }
        else if(front == back) {
            DoublyNode node = front;
            front = null;
            back = null;
            node.next = null;
            node.prev = null;
            return node;
        } else {
            DoublyNode node = front;
            front = front.next;
            front.prev = null;
            node.next = null;
            node.prev = null;
            return node;
        }
    }

    public DoublyNode popBack() {
        if(front == null && back == null) {
            return null;
        }
        else if(front == back) {
            DoublyNode node = front;
            front = null;
            back = null;
            node.next = null;
            node.prev = null;
            return node;
        } else {
            DoublyNode node = back;
            back = back.prev;
            back.next = null;
            node.next = null;
            node.prev = null;
            return node;
        }
    }
    public DoublyNode pop(DoublyNode node) {
        if(front == node) {
            popFront();
        } else if(back == node) {
            popBack();
        } else {
            DoublyNode prev = node.prev;
            DoublyNode next = node.next;
            if(prev != null) {
                prev.next = next;
            }
            if(next != null) {
                next.prev = prev;
            }
            if(node.next == null && node.prev == null) {
                front = null;
                back = null;
            }
        }
        node.next = null;
        node.prev = null;
        
        return node;
    } 
}
class LRUCache {
    public DoublyLinkedList memory;
    public HashMap<Integer, DoublyNode> cacheMap;
    public int capacity;

    public LRUCache(int capacity) {
        this.memory = new DoublyLinkedList();
        this.cacheMap = new HashMap();
        this.capacity = capacity;
    }
    public int get(int key) {
        DoublyNode node = cacheMap.get(key);
        if(node != null) {
            memory.pop(node);
            memory.pushBack(node);
            return node.value;
        } else {
            return -1;
        }
    }
    public void put(int key, int value) {
        DoublyNode node = cacheMap.get(key);
        if(node == null) {
            if(cacheMap.size() == capacity) {
                DoublyNode toDelete = memory.popFront();
                cacheMap.remove(toDelete.key);
            }
            node = new DoublyNode(key, value, null, null);
        } else {
            node.value = value;
            memory.pop(node);
        }
        memory.pushBack(node);
        cacheMap.put(key, node);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */