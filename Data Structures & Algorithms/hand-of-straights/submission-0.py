class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        n=len(hand)
        if n%groupSize:
            return False
        dd=defaultdict(int)
        for i in hand:
            dd[i]+=1
        keys=sorted(dd.keys())
        j=0
        for p in range(n//groupSize):
            while j < len(keys) and dd[keys[j]] == 0:
                j += 1
            for i in range(groupSize):
                if dd[keys[j]+i] == 0:
                    return False
                dd[keys[j]+i]-=1
            if(not dd[keys[j]]):
                j+=1
        return True



        