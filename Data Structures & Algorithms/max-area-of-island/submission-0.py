class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m=len(grid)
        n=len(grid[0])
        ma=0
        for i in range(m):
            for j in range(n):
                if(grid[i][j]):
                    ma=max(ma,self.dfs(grid,i,j,m,n))
        return ma
    
    def dfs(self,grid,i,j,m,n):
        if i<0 or j<0 or i>=m or j>=n or not grid[i][j]:
            return 0
        grid[i][j]=0
        return 1+self.dfs(grid,i+1,j,m,n) + self.dfs(grid,i-1,j,m,n) + self.dfs(grid,i,j+1,m,n) +self.dfs(grid,i,j-1,m,n)


                
        