class TrieNode {
public:
    vector<TrieNode*> children;
    bool end;

    TrieNode() : children(26, nullptr), end(false) {}
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        return dfs(word, 0 , root);
    }

private:
    bool dfs(string word, int i, TrieNode* root) {
        TrieNode* cur = root;
        for (int j = i; j < word.size(); j++) {
            char c = word[j];
            if (c == '.') {
                for (auto child : cur->children) {
                    if (child != nullptr and dfs(word, j + 1, child)) return true;
                }
                return false;
            } else {
                if (cur->children[c - 'a'] == nullptr) {
                    return false;
                }
                cur = cur->children[c - 'a'];
            }
        }

        return cur->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */