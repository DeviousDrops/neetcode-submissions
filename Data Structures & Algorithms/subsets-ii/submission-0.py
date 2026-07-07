class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        s=[]
        nums.sort()
        res=[]
        def dfs(i):  
            if(i==len(nums)):
                res.append(s.copy())
                return
            s.append(nums[i])
            dfs(i+1)
            s.pop()
            while(i+1!=len(nums) and nums[i+1]==nums[i]):
                i+=1
            dfs(i+1)
        dfs(0)
        return res