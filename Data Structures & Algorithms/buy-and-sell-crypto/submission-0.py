class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l=prices[0]
        p=0
        c=0
        for i in prices[1:]:
            c=i-l
            p=max(p,c)
            l=min(i,l)
        return p
        