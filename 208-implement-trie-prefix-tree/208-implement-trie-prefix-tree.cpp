class Trie {
public:
    struct Node {
        bool isEnd;
        Node* next[26];
        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                next[i] = NULL;
            }
        }
    } *root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *currNode = root;
        for (int i = 0; i < word.size(); i++) {
            if (currNode->next[word[i]-'a'] == NULL) {
                currNode->next[word[i]-'a'] = new Node();
            }
            currNode = currNode->next[word[i]-'a'];
        }
        currNode->isEnd = true;
        return;
    }
    
    bool search(string word) {
        Node *currNode = root;
        for (int i = 0; i < word.size(); i++) {
            if (currNode->next[word[i]-'a'] == NULL) {
                return false;
            }
            currNode = currNode->next[word[i]-'a'];
        }
        return currNode->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node *currNode = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (currNode->next[prefix[i]-'a'] == NULL) {
                return false;
            }
            currNode = currNode->next[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */