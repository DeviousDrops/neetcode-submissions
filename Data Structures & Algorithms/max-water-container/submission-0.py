class Solution:
    def maxArea(self, height: List[int]) -> int:
        l,r=0,len(height)-1
        ma=0
        while(l<r):
            small=min(height[l],height[r])
            ma=max(ma,small*(r-l))
            if height[l]<height[r]:
                l+=1
            else:
                r-=1
        return ma
                
        
        