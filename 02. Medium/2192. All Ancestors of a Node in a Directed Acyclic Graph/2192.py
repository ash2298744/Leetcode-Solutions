class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        g = {i : set() for i in range(n)}
        for i in edges:
            g[i[1]].add(i[0])
        
        def dfs(node):
            for i in g[node]:
                if i not in nodeAncs:
                    nodeAncs.add(i)
                    dfs(i)
        
        ancs = []
        for i in range(n):
            nodeAncs = set()
            dfs(i)
            ancs.append(sorted(nodeAncs))
        return ancs
