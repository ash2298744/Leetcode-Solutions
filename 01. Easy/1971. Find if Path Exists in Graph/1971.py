class Solution:
    def dfs(self, node, g, vis):
        vis.add(node)
        for child in g[node]:
            if child not in vis:
                self.dfs(child, g, vis)

    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        vis = set()
        g = [[] for _ in range(n)]
        for i in edges:
            g[i[0]].append(i[1])
            g[i[1]].append(i[0])
        
        self.dfs(source, g, vis)
        return source in vis and destination in vis
