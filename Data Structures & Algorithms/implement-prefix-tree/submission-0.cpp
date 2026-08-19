class PrefixTree {
public:
    class TrieNode {
    public:
        TrieNode *children[26];
        bool isEndWord;
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isEndWord = false;
        } 
    };

    TrieNode *root;

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curNode = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curNode->children[idx] == nullptr) {
                curNode->children[idx] = new TrieNode();
            }
            curNode = curNode->children[idx];
        }
        curNode->isEndWord = true;
    }
    
    bool search(string word) {
        TrieNode *curNode = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curNode->children[idx] == nullptr) return false;
            curNode = curNode->children[idx];
        }
        return curNode->isEndWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curNode = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (curNode->children[idx] == nullptr) return false;
            curNode = curNode->children[idx];
        }
        return true;        
    }
};
