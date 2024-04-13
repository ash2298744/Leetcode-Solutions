class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        row, col = len(matrix), len(matrix[0])

        dpL = [[0 for i in range(col)] for i in range(row)]
        dpR = [[0 for i in range(col)] for i in range(row)]
    
        for i in range(row):
            dpL[i][0] = int(matrix[i][0])
            for j in range(1, col):
                if matrix[i][j] == '1':
                    dpL[i][j] += dpL[i][j - 1] + 1
        
        for i in range(row):
            dpR[i][col - 1] = int(matrix[i][col - 1])
            for j in range(col - 2, -1, -1):
                if matrix[i][j] == '1':
                    dpR[i][j] += dpR[i][j + 1] + 1
        
        maxArea = 0
        for i in range(row):
            for j in range(col):
                curr = max(dpL[i][j], dpR[i][j])
                b = 1
                l = col + 1
                k = i
                while k < row and matrix[k][j] == '1' and max(dpL[i][j], dpR[i][j]) <= curr:
                    l = min(l, dpR[k][j])
                    maxArea = max(maxArea, l * b)
                    k += 1
                    b += 1   
        return maxArea
