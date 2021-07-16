class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        # Create a directed, and undirected adjacency graph
        directed = [[] for _ in range(n)]
        undirected = [[] for _ in range(n)]
        for connect in connections:
            u, v = connect[0], connect[1]
            directed[u].append(v)
            undirected[u].append(v)
            undirected[v].append(u)
        
        # <visited> to avoid revisiting in undirected graph
        visited = [False] * n
        visited[0] = True
        s = [0] # stack
        count = 0 # number of edge to reverse
        
        # DFS
        while len(s) > 0:
            u = s.pop()
            for v in undirected[u]:
                if not visited[v]:
                    visited[v] = True
                    # Traversing from 0 out, so if
                    # have edge u->v, we need to reverse
                    # this edge
                    if v in directed[u]:
                        count += 1
                    s.append(v)
        return count
