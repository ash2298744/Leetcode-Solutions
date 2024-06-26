class Solution {
private:
    void dfs(int row, int col, int i, int j, vector<vector<char>> &grid) {
        if(i < 0 || j < 0 || i == row || j == col || grid[i][j] != '1') return;
        grid[i][j] = '0';
        dfs(row, col, i + 1, j, grid);
        dfs(row, col, i, j + 1, grid);
        dfs(row, col, i - 1, j, grid);
        dfs(row, col, i, j - 1, grid);
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int islands = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == '1') {
                    islands++;
                    dfs(row, col, i, j, grid);
                }
            }
        }
        return islands;
    }
};
