class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        visited=set()
        ans=False
        def dfs(r,c,i):
            l=r*len(board[0])+c
            nonlocal ans
            if i==len(word):
                ans=True
                return
            if ans or r>=len(board) or c>=len(board[0]) or r<0 or c<0  or l in visited or board[r][c]!=word[i]:
                return
            visited.add(l)
            dfs(r+1,c,i+1)
            dfs(r,c+1,i+1)
            dfs(r,c-1,i+1)
            dfs(r-1,c,i+1)
            visited.discard(l)
        for j in range(len(board)):
            for p in range(len(board[0])):
                dfs(j,p,0)
        return ans