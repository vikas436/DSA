/** https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/
 *
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int>>vec;
    if(A==NULL) return vec;
    map < int,vector<int> > m;
    queue<pair<TreeNode*, int> > que;
    que.push(make_pair(A, 0));
    int h=0;
    m[h].push_back(A->val);
    while(!que.empty()) {
        pair<TreeNode*, int> pr = que.front();
        que.pop();
        h = pr.second;
        TreeNode *node = pr.first;
        if(node->left!=NULL) {
            que.push(make_pair(node->left, h-1));
            m[h-1].push_back(node->left->val);
        }
        if(node->right!=NULL) {
            que.push(make_pair(node->right, h+1));
            m[h+1].push_back(node->right->val);
        }
    }
    
    for(auto it=m.begin();it!=m.end();it++) {
        vector<int> arr = it->second;
        vec.push_back(arr);
    }
    return vec;
}
