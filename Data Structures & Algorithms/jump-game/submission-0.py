class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n=len(nums)
        if n==1:
            return True
        m=0
        for i in range(n):
            m=max(m,nums[i]+i)
            if m>=n-1:
                return True
            elif nums[i]==0 and m==i:
                return False
        return True