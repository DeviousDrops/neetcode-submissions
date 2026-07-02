class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        pq=[]
        for i in points:
            heapq.heappush(pq,(-(i[0]**2+i[1]**2),i))
            if(len(pq)>k):
                heapq.heappop(pq)    
        res=[]
        for i in pq:
            res.append(i[1])
        return res