class Solution:
    def findMin(self, nums: List[int]) -> int:
        l,r=0,len(nums)-1
        m=min(nums[r],nums[l])
        while(l<=r):
            mid=l+(r-l)//2
            print(mid)
            m=min(nums[mid],m)
            if nums[mid]>=nums[r] and nums[mid]>=nums[l]:
                l=mid+1
            else:
                r=mid-1
        return m

        