class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adj=[[] for i in range(n)]
        for i in edges:
            adj[i[1]].append(i[0]) #1: 0,2  2:1  3:4
            adj[i[0]].append(i[1]) #0: 1
        v=set()
        c=0
        def dfs(i:int):
            if i in v:
                return
            v.add(i)
            for j in adj[i]:
                dfs(j)

        for i in range(n):
            if i in v:
                continue
            print(i)
            dfs(i)
            c+=1
        
        return c

        