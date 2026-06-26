class Solution:
    m=float('-inf')
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.helper(root)
        return self.m
    def helper(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        l=max(0,self.helper(root.left))
        r=max(0,self.helper(root.right))
        self.m=max(root.val+l+r,self.m)
        return max(l,r)+root.val
        