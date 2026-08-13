class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        g=[set() for _ in range(n)]
        for i in edges:
            g[i[0]].add(i[1])
            g[i[1]].add(i[0])
        queue=deque()
        queue.append(0)
        v=set({0})
        while(len(queue)!=0):
            k=queue.popleft()
            for i in g[k]:
                if i in v:
                    return False
                v.add(i)
                g[i].remove(k)
                queue.append(i)
        return len(v)==n

        