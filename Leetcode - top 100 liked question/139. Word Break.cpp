class Solution {
public:
    struct Trie {
        Trie *arr[26];
        bool isEnd;
    };
    Trie* getNode() {
        Trie *trie = new Trie();
        for(int i=0;i<26;i++) {
            trie->arr[i] = NULL;
        }
        trie->isEnd = false;
        return trie;
    }
    void createNode(Trie *node, string str) {
        for(int i=0;i<str.size();i++) {
            if(node->arr[str[i]-'a']==NULL) {
                node->arr[str[i]-'a'] = getNode();
            }
            node = node->arr[str[i]-'a'];
        }
        node->isEnd = true;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie *node = getNode();
        for(int i=0;i<wordDict.size();i++)
            createNode(node, wordDict[i]);
        vector<bool>dp(s.size()+1,false);
        dp[0]=true;
        for(int i=0;i<s.size();i++) {
            if(dp[i]) {
                 Trie *root = node;
                for(int j=i;j<s.size();j++) {
                    if(root->arr[s[j]-'a']==NULL) break;
                    root=root->arr[s[j]-'a'];
                    if(root->isEnd) dp[j+1]=true;
                }
            }
        }
        return dp[s.size()];
    }
};
