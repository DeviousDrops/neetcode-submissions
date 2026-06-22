/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
unordered_map<int,bool> mp;
TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        srch(root,p);
        srch(root,q);
        return ans;
    }
    void srch(TreeNode* root, TreeNode* p){
        if(mp[root->val])
            ans=root;
        else
            mp[root->val]=true;
        if(root->val==p->val)
            return;
        else if(root->val<p->val)
            srch(root->right,p);
        else
            srch(root->left,p);
    }
};