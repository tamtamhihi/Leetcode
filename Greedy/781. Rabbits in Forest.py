from math import ceil

class Solution:
    # For rabbits that have the same answer of k,
    # the greedy solution is to assume that they are
    # in the same color group with size of k+1.
    
    # However, if more than k+1 rabbits have answer of k,
    # we must consider them into different groups, but 
    # these groups happen to have the same size of (k+1).
    
    def numRabbits(self, answers: List[int]) -> int:
        same_answer = dict()
        for answer in answers:
            if answer not in same_answer.keys():
                same_answer[answer] = 1
            else:
                same_answer[answer] += 1
        total = 0
        for answer in same_answer:
            group_size = answer + 1
            num_groups = int(ceil(same_answer[answer] / group_size))
            total += group_size * num_groups
        return total
