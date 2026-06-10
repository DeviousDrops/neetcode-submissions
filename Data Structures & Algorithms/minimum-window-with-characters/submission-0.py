class Solution:
    def minWindow(self, s: str, t: str) -> str:
        freq=defaultdict(int)
        if len(t)==0:
            return ""
        for c in t:
            freq[c]+=1
        l,r=0,0
        count=defaultdict(int)
        rcount=defaultdict(int)
        while(l<len(s) and s[l] not in freq):
            l+=1
        r=l
        ans=[-1,len(s)]
        while(r<len(s) and l<len(s)):           
            if s[r] in freq:
                if freq[s[r]]>count[s[r]]:
                    count[s[r]]+=1
                rcount[s[r]]+=1
            if count==freq:
                if ans[1]-ans[0]>=r-l:
                    ans=[l,r] 
                if rcount[s[l]]==count[s[l]]:
                    count[s[l]]-=1                    
                rcount[s[l]]-=1
                if l!=r:
                    rcount[s[r]]-=1
                    count[s[r]]-=1
                else:
                    r+=1
                l+=1
                while(l<r and s[l] not in freq):
                    l+=1
            else:
                r+=1
        if ans[0]==-1:
            return ""
        l,r=ans[0],ans[1]
        return s[l:r+1]   
            
            