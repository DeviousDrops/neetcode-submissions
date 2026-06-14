class TimeMap:

    def __init__(self):
        self.d=defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.d[key].append([value,timestamp])

    def get(self, key: str, timestamp: int) -> str:
        l=0
        if key not in self.d:
            return ""
        r=len(self.d[key])-1
        ans=""
        k=0
        while(l<=r):
            mid=l+(r-l)//2
            if(self.d[key][mid][1]<=timestamp):
                l=mid+1
                if self.d[key][mid][1]>=k:
                    k=self.d[key][mid][1]
                    ans=self.d[key][mid][0]
            else:
                r=mid-1
        return ans


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)