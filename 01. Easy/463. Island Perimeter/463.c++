class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        vector<vector<int>> newGrid(row + 2, vector<int>(col + 2, 0));
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                newGrid[i + 1][j + 1] = grid[i][j];
            }
        }
        
        row += 2;
        col += 2;

        vector<pair<int, int>> dircn = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int perimeter = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(!newGrid[i][j]) {
                    for(auto &k : dircn) {
                        int dx = k.first, dy = k.second;
                        if((i + dx) >= 0 && (j + dy) >= 0 && (i + dx) < row && (j + dy) < col && newGrid[i + dx][j + dy]) {
                            perimeter++;
                        }
                    }
                }
                
            }
        }
        return perimeter;
    }
};
