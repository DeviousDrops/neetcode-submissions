from functools import lru_cache 
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        @lru_cache(None)
        def dfs(i,h):
            if i>=len(prices):
                return 0
            if h==1:
                return max(prices[i]+dfs(i+2,0),dfs(i+1,1))
            if h==0:
                return max(-prices[i]+dfs(i+1,1),dfs(i+1,0))
        return dfs(0,0)