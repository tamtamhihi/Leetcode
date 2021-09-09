import sys
sys.setrecursionlimit(10 ** 5)

class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        n = len(tickets)
        # Construct an adjacency list for the graph
        graph = dict()
        for ticket in tickets:
            source, dest = ticket[0], ticket[1]
            if source not in graph:
                graph[source] = []
            graph[source].append(dest)
        # Sort the neighbors in increasing lexicographic order
        for source in graph:
            graph[source].sort()
        
        self.ans = []
        
        # Construct the reverse of the 
        # lexicographically smallest Eulerian path/cycle
        # and store into <ans>.
        def dfs(source):
            # From each source, try to start from the smallest neighbor,
            # and pop this neighbor out
            if source in graph:
                while len(graph[source]) > 0:
                    dfs(graph[source].pop(0))
            # Append source 
            self.ans.append(source)
        
        dfs('JFK')
        self.ans.reverse()
        return self.ans
