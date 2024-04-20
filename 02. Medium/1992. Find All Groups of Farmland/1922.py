class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        row, col = len(land), len(land[0])
        ans = []
        for i in range(row):
            for j in range(col):
                if land[i][j]:
                    curr = (i, j)
                    q = deque([[i, j]])
                    while q:
                        x, y = q.popleft()
                        for dx, dy in [[1, 0], [0, -1], [0, 1], [-1, 0]]:
                            ii, jj = x + dx, y + dy
                            if ii < 0 or jj < 0 or ii == row or jj == col or land[ii][jj] == 0:
                                continue
                            land[ii][jj] = 0
                            curr = max(curr, (ii, jj))
                            q.append([ii, jj])
                    ans.append([i, j, curr[0], curr[1]])
        return ans   
