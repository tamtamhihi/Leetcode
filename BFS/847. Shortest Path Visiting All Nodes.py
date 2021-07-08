import queue

class Solution:
    
    # Let the original graph be G.
    
    # We will BFS on a graph G1 where:
    # - Each vertex in G1 represents a node <i> in G and the set
    # visited nodes
    # - There's an edge between 2 vertices (i, visited_i) and 
    # (j, visited_j) if there's an edge between i and j in G
    
    # Since we can start the path from any node in G, the BFS
    # will start simultaneously from all vertices (i, state_i)
    # where state_i contains only i (there's only 1 visited node)
    
    # The destination is any vertex of any node, but the set of visited
    # nodes contain all nodes in G.
    
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n = len(graph)
        
        # A queue for BFS
        states = queue.Queue()
        
        # The visited set for G1
        visited = set()
        
        # We can start from all nodes i, with the initial visited
        # set containing only i. Here we use bitmask to represent 
        # the visited nodes.
        for i in range(n):
            initial = (1 << i)
            states.put((i, initial))
            visited.add((i, initial))
        
        # This is the destination visited set (all n nodes are visited)
        final = (1 << n) - 1
        
        step = 0
        # Iterate through each level in G1
        while not states.empty():
            curLen = states.qsize()
            for _ in range(curLen):
                vertex, state = states.get()
                for neighbor in graph[vertex]:
                    # Add the neighbor to the visited set
                    nextState = state | (1 << neighbor)
                    if nextState == final:
                        return step + 1
                    if (neighbor, nextState) not in visited:
                        states.put((neighbor, nextState))
                        visited.add((neighbor, nextState))
            step += 1
        return 0
