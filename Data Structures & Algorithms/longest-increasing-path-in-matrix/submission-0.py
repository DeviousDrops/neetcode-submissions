from functools import cache
class Solution:
    def longestIncreasingPath(self, matrix: list[list[int]]) -> int:
        d=[[0,1],[1,0],[-1,0],[0,-1]]
        @cache
        def dfs(i,j):
            m=0
            for [p,q] in d:
                if(i+p<len(matrix) and j+q<len(matrix[0]) and i+p>=0 and j+q>=0 and matrix[i][j]<matrix[i+p][j+q]):
                    m=max(m,dfs(i+p,j+q))
            return m+1
        ans=0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                ans=max(ans,dfs(i,j))
        return ans