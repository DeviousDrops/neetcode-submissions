class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.yelp(root,pow(-2,31)-1,pow(2,31)+1)
    
    def yelp(self, root: Optional[TreeNode],mi: int,ma: int)->bool:
        if not root:
            return True
        if root.left and (root.left.val>=root.val or root.left.val<=mi) or root.right and (root.right.val<=root.val or root.right.val>=ma):
            return False
        return self.yelp(root.left,mi,root.val) and self.yelp(root.right,root.val,ma)