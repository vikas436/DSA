/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res;
    void dfs(TreeNode *node, TreeNode *pre, set<TreeNode*> &st) {
        if(node==NULL) return;
        dfs(node->left, node, st);
        dfs(node->right, node, st);
        if(pre==NULL && !st.count(node) 
           || !st.count(node->left) || !st.count(node->right)) {
            res++;
            st.insert(pre);
            st.insert(node);
            st.insert(node->left);
            st.insert(node->right);
        }
    }
    
    int minCameraCover(TreeNode* root) {
        res=0;
        set<TreeNode*> st;
        st.insert(NULL);
        dfs(root, NULL, st);
        return res;
    }
};
