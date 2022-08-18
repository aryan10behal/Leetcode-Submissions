class Solution:
    def countArrangement(self, n: int) -> int:
        self.output = 0
        
        def backtrack(perm, i):
            if i == n + 1:
                self.output += 1
            else:
                for j in range(1, n + 1):
                    if j not in perm and (not perm or j % i == 0 or i % j == 0):
                        backtrack(perm + [j], i + 1)
                        
        backtrack([], 1)
        return self.output