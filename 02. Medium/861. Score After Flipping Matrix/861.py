class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])

        for i in range(row):
            if grid[i][0] == 0:
                for j in range(col):
                    grid[i][j] ^= 1
        
        for j in range(col):
            one = zero = 0
            for i in range(row):
                one += (grid[i][j])
                zero += (1 - grid[i][j])
            
            if zero > one:
                for i in range(row):
                    grid[i][j] ^= 1
        
        res = 0
        for i in range(row):
            cur = 0
            for j in range(col):
                cur |= (grid[i][j] << (col - j - 1))
            res += cur
        return res
