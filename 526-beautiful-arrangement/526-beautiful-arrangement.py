class Solution:
    def countArrangement(self, N: int) -> int:
        states = set([i for i in range(1, N+1)])
        count = 0
        def helper(curr, i, states):
            if curr % i != 0 and i % curr != 0:
                return
            if len(states) == 0:
                nonlocal count
                count += 1
            for num in states:
                helper(num, i+1, states-set([num]))

        for i in states:
            helper(i, 1, states-set([i]))
        return count