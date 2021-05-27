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
    void rec(TreeNode* node,  vector<TreeNode*> &res, unordered_set<int>&st, bool f) {
        if(node==NULL) return;
        if(st.count(node->val)) {
            rec(node->left, res, st, true);
            rec(node->right, res, st, true);
        } else {
            if(f) res.push_back(node);
            TreeNode* l = node->left;
            TreeNode* r = node->right;
            if(l && st.count(l->val)) {
                node->left = NULL;
            }
            if(r && st.count(r->val)) {
                node->right = NULL;
            }
            rec(l, res, st, false);
            rec(r, res, st, false);
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>st;
        for(int i=0;i<to_delete.size();i++) {
            st.insert(to_delete[i]);
        }
        vector<TreeNode*> res;
        rec(root, res, st, true);  
        return res;
    }
};
