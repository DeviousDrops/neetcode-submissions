# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    m=0
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.helper(root)
        return self.m
    def helper(self ,root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        l=self.helper(root.left)
        r=self.helper(root.right)
        self.m=max(l+r,self.m)
        return max(l,r) + 1