"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        intervals=sorted(intervals, key=lambda x: x.start)
        if not len(intervals):
            return 0
        hp=[intervals[0].end]
        m=1
        for i in range(1,len(intervals)):
            while(len(hp) and intervals[i].start>=hp[0]):
                heapq.heappop(hp)
            heapq.heappush(hp,intervals[i].end)
            m=max(m,len(hp))

        
        return m
        