class Solution:
    def combinationSum2(self, c: List[int], t: int) -> List[List[int]]:
        c.sort()
        res=[]
        s=[]
        def dfs(total, i):
            if total==t:
                res.append(s.copy())
                return
            elif i==len(c) or t<total:
                return
            s.append(c[i])
            dfs(total+c[i],i+1)
            s.pop()
            while(i+1<len(c) and c[i]==c[i+1]):
                i+=1
            dfs(total,i+1)
        dfs(0,0)
        return res