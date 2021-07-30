from queue import PriorityQueue

class Node:
    def __init__(self, node, dist):
        self.node = node
        self.dist = dist
    def __lt__(self, other):
        return self.dist < other.dist

class Solution:
    def reachableNodes(self, edges: List[List[int]], maxMoves: int, n: int) -> int:
        # Convert to adjacency list
        graph = [[] for _ in range(n)]
        for edge in edges:
            graph[edge[0]].append((edge[1], edge[2]))
            graph[edge[1]].append((edge[0], edge[2]))
            
        # Dijkstra algorithm
        pq = PriorityQueue() # min-heap
        pq.put(Node(0, 0))
        dist = [10 ** 9] * n
        dist[0] = 0
        
        while len(pq.queue) > 0:
            node = pq.get()
            u = node.node
            if dist[u] != node.dist:
                continue
            for v, num in graph[u]:
                # Only update dist[v] if we can arrive at v without exceeding maxMoves,
                # and also it's a shorter path to v.
                if dist[u] + num + 1 <= maxMoves and dist[u] + num + 1 < dist[v]:
                    dist[v] = dist[u] + num + 1
                    pq.put(Node(v, dist[v]))
        
        ans = 0
        
        # Find all reachable main nodes
        for i in range(n):
            if dist[i] != 10 ** 9:
                ans += 1
                
        # Find reachable nodes on each edge.
        for edge in edges:
            u, v, num = edge[0], edge[1], edge[2]
            if dist[u] == 10 ** 9 and dist[v] == 10 ** 9:
                continue
            
            # Number of nodes cannot exceed num
            un = min(maxMoves - dist[u], num)
            vn = min(maxMoves - dist[v], num)
            if dist[u] == 10 ** 9:
                ans += vn
            elif dist[v] == 10 ** 9:
                ans += un
            else:
                ans += min(num, un + vn)
        return ans
