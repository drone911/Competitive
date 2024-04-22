class TrieNode {
    TrieNode[] children;
    boolean endNode;
}
class WordDictionary {
    private TrieNode root;

    public WordDictionary() {
        root = new TrieNode();
        root.children = new TrieNode[26];
    }
    
    public void addWord(String word) {
        TrieNode curr = root;
        int n = word.length();
        for(int i=0; i<n; i++) {
            if(curr.children == null) {
                curr.children = new TrieNode[26];
            }
            int chIndex = (int)word.charAt(i) - (int)'a';
            TrieNode child = curr.children[chIndex];
            if(child == null) {
                child = new TrieNode();
                curr.children[chIndex] = child;
            }
            curr = child;
        }
        curr.endNode = true;
    }
    
    public boolean search(String word) {
        return search(root, word);
    }
    public boolean search(TrieNode start, String word) {
        TrieNode curr = start;
        int n = word.length();
        for(int i=0; i<n; i++) {
            if(curr.children == null) {
                return false;
            }
            char ch = word.charAt(i);
            if(ch == '.') {
                String subString = word.substring(i+1);
                for(int j=0; j<26; j++) {
                    TrieNode child = curr.children[j];
                    if(child != null) {
                        if(search(child, subString)) {
                            return true;
                        }
                    }
                }
                return false;
            } else {
                int chIndex = (int)ch - (int)'a';
                TrieNode child = curr.children[chIndex];
                if(child == null) {
                    return false;
                }    
                curr = child;
            }
        }
        return curr.endNode;

    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */