class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        # Adjacency list (0-indexed)
        graph = [[] for _ in range(n)]
        for edge in edges:
            u, v = edge[0] - 1, edge[1] - 1
            graph[u].append(v)
            graph[v].append(u)
        target -= 1
        
        dist = [-1] * n # distance from root (0)
        dist[0] = 0
        prob = [1] * n # probability to go from root
        isLeaf = [False] * n
        
        # Stack s saves current node and its parent
        s = [(0, -1)]
        while len(s) > 0:
            u, parent = s.pop()
            count = 0
            for v in graph[u]:
                choices = len(graph[u]) if parent == -1 else len(graph[u]) - 1
                if v != parent:
                    dist[v] = dist[u] + 1
                    prob[v] *= prob[u] / choices
                    s.append([v, u])
                    count += 1
            if count == 0:
                isLeaf[u] = True
        # If this is a leaf node
        if isLeaf[target]:
            # We can reach this node when
            # there's enough time to reach it
            if dist[target] <= t:
                return prob[target]
            return 0
        else:
            # If this is not a leaf node,
            # we can only reach here when
            # time is exactly enough to
            # reach here
            if dist[target] == t:
                return prob[target]
            return 0
            
