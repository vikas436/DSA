class Trie {
public:
    /** Initialize your data structure here. */
    const int size = 26;
    struct trie {
        struct trie* arr[26];
        bool isEnd;
        
    };
    struct trie *head;
    Trie() {
        head = getNode(); 
    }
    
    trie* getNode() {
        trie *node = new trie();
        node->isEnd = false;
        for(int i=0;i<size;i++) {
            node->arr[i]=NULL;
        }
        return node;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        trie* root = head;
        for(int i=0;i<word.size();i++) {
            int ind = word[i]-'a';
            if(root->arr[ind]) {
                root = root->arr[ind];   
            } else {
                root->arr[ind] = getNode();
                root = root->arr[ind];
            }
        }
        root->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trie* root = head;
        for(int i=0;i<word.size();i++) {
            int ind = word[i]-'a';
            if(root->arr[ind]) {
                root = root->arr[ind]; 
            } else return false;
        }
        if(root && root->isEnd==true) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trie* root = head;
        for(int i=0;i<prefix.size();i++) {
            int ind = prefix[i]-'a';
            if(root->arr[ind]) {
                root = root->arr[ind]; 
            } else return false;
        }
        if(root) return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
