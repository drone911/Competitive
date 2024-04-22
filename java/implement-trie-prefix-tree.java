class TrieNode {
    HashMap<Character, TrieNode> children;
    boolean rootNode;
}
class Trie {
    private TrieNode root;
    public Trie() {
        root = new TrieNode();
        root.children = new HashMap<>();
    }
    
    public void insert(String word) {
        TrieNode curr = root;
        for(Character c: word.toCharArray()) {
            if(curr.children == null) {
                curr.children = new HashMap<>();
            }
            TrieNode childPresent = curr.children.get(c);
            if(childPresent != null) {
                curr = childPresent;
            } else {
                childPresent = new TrieNode();
                curr.children.put(c, childPresent);
                curr = childPresent;
            }
        }
        curr.rootNode = true;
    }
    
    public boolean search(String word) {
        TrieNode curr = root;
        for(Character c: word.toCharArray()) {
            if(curr.children == null) {
                return false;
            }
            TrieNode childPresent = curr.children.get(c);
            if(childPresent != null) {
                curr = childPresent;
            } else {
                return false;
            }
        }
        return curr.rootNode;
    }
    
    public boolean startsWith(String prefix) {
        TrieNode curr = root;
        for(Character c: prefix.toCharArray()) {
            if(curr.children == null) {
                return false;
            }
            TrieNode childPresent = curr.children.get(c);
            if(childPresent != null) {
                curr = childPresent;
            } else {
                return false;
            }
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
