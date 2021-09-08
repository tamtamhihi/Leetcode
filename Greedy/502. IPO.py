from queue import PriorityQueue

class Solution:
    # The main idea: Among all available projects (capital <= w),
    # always choose the project with largest profit
    # => maximize final capital and quickly increase w
    # => ịncrease choices of available projects
    
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        # Store the projects
        projects = [(profits[i], capital[i]) for i in range(len(profits))]
        # Sort the projects in terms of increasing capital
        projects.sort(key=lambda x : x[1])
        
        pq = PriorityQueue()
        index = 0
        count = 0
        while count < k:
            # Add new available projects to the heap
            while index < len(projects) and projects[index][1] <= w:
                pq.put(-projects[index][0])
                index += 1
            if len(pq.queue) == 0:
                break
            w += -pq.get()
            count += 1
        return w
