class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        mp=defaultdict(int)
        a=s[0]
        l=0
        r=0
        n=k
        while(r<len(s)):    
            mp[s[r]]+=1
            if mp[s[r]] > mp[a]:
                a=s[r]
            if mp[a]+k<r-l+1:
                mp[s[l]]-=1
                l+=1
            r+=1
            
        return r-l