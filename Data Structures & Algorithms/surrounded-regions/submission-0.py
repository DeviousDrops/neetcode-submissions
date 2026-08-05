class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        dr=[[0,1],[0,-1],[1,0],[-1,0]]
        def dfs(r,c):
            if r<0 or c<0 or r>=m or c>=n or r*n+c in s or board[r][c]=="X":
                return
            s.add(r*n+c)
            for i in range(4):
                dfs(r+dr[i][0],c+dr[i][1])
            
        m=len(board)
        n=len(board[0])
        s=set()
        for i in range(n):
            dfs(0,i)
            print(i)
            dfs(m-1,i)
        for j in range(1,m-1):
            dfs(j,0)
            dfs(j,n-1)
        for i in range(m):
            for j in range(n):
                if i*n+j not in s and board[i][j]=="O":
                    board[i][j]="X"
        

        