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
    string res = "";
    void rec(TreeNode *node, string st) {
        if(!node) return;
        if(node && !node->left && !node->right) {
            char c=('a'+node->val);
            st=st+c;
            reverse(st.begin(), st.end());
            if(res.size()==0) res=st; 
            if(res.compare(st)>0) res=st;
            return;
        }
        char c=('a'+node->val);
        rec(node->left, st+c);
        c=('a'+node->val);
        rec(node->right, st+c);
    }
    string smallestFromLeaf(TreeNode* root) {
        if(root==NULL) return "";
        res="";
        rec(root, "");
        return res;
    }
};
