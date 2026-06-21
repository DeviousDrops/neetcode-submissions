# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not root:
            return False
        return root.val == subRoot.val and self.isSame(root,subRoot) or self.isSubtree(root.left,subRoot) or self.isSubtree(root.right,subRoot)
            
    
    def isSame(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and q or not q and p:
            return False
        elif not p and not q:
            return True
        return p.val==q.val and self.isSame(p.left,q.left) and self.isSame(p.right,q.right)
        