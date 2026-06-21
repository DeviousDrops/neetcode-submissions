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
    int m=0;
    bool isBalanced(TreeNode* root) {
        bal(root);
        return m<2;
    }

    int bal(TreeNode* root){
        if(!root)
            return 0;
        int lc=bal(root->left);
        int rc=bal(root->right);
        m=max(abs(lc-rc),m);
        return max(lc,rc)+1;

    }
};