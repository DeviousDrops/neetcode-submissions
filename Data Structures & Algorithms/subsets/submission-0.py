class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.ans=[]
        self.help(nums,0,[])
        return self.ans
    def help(self,nums: List[int],i, s:List[int]):
        if i==len(nums):
            self.ans.append(s[:])
            return
        self.help(nums,i+1,s)
        s.append(nums[i])
        self.help(nums,i+1,s)
        s.pop()

        
        