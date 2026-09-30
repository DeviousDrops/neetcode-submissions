from functools import cache
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        @cache
        def dfs(i,j):  
            if j==len(t):
                return 1
            if len(s)-i<len(t)-j:
                return 0
            k=0
            if s[i]==t[j]:
                k=dfs(i+1,j+1)
            k+=dfs(i+1,j)
            return k
        return dfs(0,0)
        