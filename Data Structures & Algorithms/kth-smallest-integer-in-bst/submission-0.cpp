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
int p;
int ans;
    int kthSmallest(TreeNode* root, int k) {
      p=k;
      helper(root);
      return ans;
    }

    void helper(TreeNode* root){
        if(!root || p==0)
            return;
        helper(root->left);
        p--;
        if(p==0)
        {
            ans=root->val;
            return;
        }
        helper(root->right);
    }
};