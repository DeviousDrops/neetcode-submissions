class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res=[]
        s=""
        d={"2":"abc","3":"def","4":"ghi","5":"jkl","6":"mno","7":"pqrs","8":"tuv","9":"wxyz"}
        def dfs(i):
            nonlocal s
            if i==len(digits):
                res.append(s[:])
                return
            for _ in d[digits[i]]:
                s+=_
                dfs(i+1)
                s=s[:-1]
        if digits=="":
            return []
        dfs(0)
        return res  