class Solution:
    def isValid(self, s: str) -> bool:
        a=[]
        d={'(':')','{':'}','[':']'}
        for i in s:
            if i in d:
                a.append(i)
            else:
                if len(a)==0 or d[a[-1]]!=i:
                    return False
                else:
                    a.pop()
        return len(a)==0
        
        