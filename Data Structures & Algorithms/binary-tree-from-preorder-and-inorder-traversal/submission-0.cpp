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
unordered_map<int,int> mp;
unordered_set<int> k;
vector<int> pr,in;
int i=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pr=preorder;
        in=inorder;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i+1;
        TreeNode* root=helper(pr[i]);
        return root;
    }
    TreeNode* helper(int l){
        TreeNode* root=new TreeNode(l);
        k.insert(mp[root->val]);
        if(mp[root->val]-1>0 && k.find(mp[root->val]-1)==k.end()){
            root->left=helper(pr[++i]);}
        if(mp[root->val]+1<=pr.size() && k.find(mp[root->val]+1)==k.end()){
            root->right=helper(pr[++i]);}
        return root;
    }
};