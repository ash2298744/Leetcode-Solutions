class Solution {
public:
    void dfs(int i, int j, int row, int col, int gold, int &ans, vector<vector<int>> &grid) {
        if(i < 0 || i == row || j < 0 || j == col || !grid[i][j]) {
            ans = max(ans, gold);
            return;
        }
        int curr = grid[i][j];
        grid[i][j] = 0;
        dfs(i + 1, j, row, col, gold + curr, ans, grid);
        dfs(i, j + 1, row, col, gold + curr, ans, grid);
        dfs(i - 1, j, row, col, gold + curr, ans, grid);
        dfs(i, j - 1, row, col, gold + curr, ans, grid);
        grid[i][j] = curr;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int ans = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j]) {
                    dfs(i, j, row, col, 0, ans, grid);
                }
            }
        }
        return ans;
    }
};
