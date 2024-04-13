class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        row, col = len(matrix), len(matrix[0])

        dpL = [[0 for i in range(col)] for i in range(row)]
        dpR = [[0 for i in range(col)] for i in range(row)]
    
        for i in range(row):
            cnt = 0
            for j in range(col):
                if matrix[i][j] == '0':
                    cnt = 0
                else:
                    cnt += 1
                    dpL[i][j] = cnt
        
        for i in range(row):
            cnt = 0
            for j in range(col - 1, -1, -1):
                if matrix[i][j] == '0':
                    cnt = 0
                else:
                    cnt += 1
                    dpR[i][j] = cnt
        
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

          