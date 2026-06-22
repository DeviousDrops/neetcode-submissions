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
    vector<vector<int>> ans;
    unordered_set<int> k;
    vector<vector<int>> levelOrder(TreeNode* root) {
        helper(root,0);
        return ans;
    }

    void helper(TreeNode* root, int c){
        if(!root)
            return;
        if(k.find(c)==k.end()){
            k.insert(c);
            ans.push_back({root->val});
        }
        else
            ans[c].push_back(root->val);
        helper(root->left,c+1);
        helper(root->right,c+1);
    }
};