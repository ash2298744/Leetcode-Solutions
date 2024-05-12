class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> res(row - 2, vector<int>(col - 2));
        for(int i = 0; i < row - 2; i++) {
            for(int j = 0; j < col - 2; j++) {
                int mx = 0;
                for(int ii = i; ii < i + 3; ii++) {
                    for(int jj = j; jj < j + 3; jj++) {
                        mx = max(mx, grid[ii][jj]);
                    }
                }
                res[i][j] = mx;
            }
        }
        return res;
    }
};
