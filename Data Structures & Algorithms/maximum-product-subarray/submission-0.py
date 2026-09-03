class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        product=1
        m=nums[0]
        n=1
        for i in range(0,len(nums)):
            if product==0:
                product=nums[i]
            else:
                product=product*nums[i]
            if nums[i]<0 and n==1:
                n=product
                continue
            elif nums[i]==0:
                n=1
            if product<0:
                m=max(m,product/n)
            else:
                m=max(m,product)
        return int(m)