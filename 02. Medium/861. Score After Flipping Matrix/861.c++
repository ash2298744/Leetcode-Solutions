class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        for(int i = 0; i < row; i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < col; j++) {
                    grid[i][j] ^= 1;
                }
            }
        }

        for(int j = 0; j < col; j++) {
            int one = 0, zero = 0;
            for(int i = 0; i < row; i++) {
                one += (grid[i][j]);
                zero += (1 - grid[i][j]);
            }
            if(zero > one) {
                for(int i = 0; i < row; i++) {
                    grid[i][j] ^= 1;
                }
            }
        }

        int res = 0;
        for(int i = 0; i < row; i++) {
            int cur = 0;
            for(int j = 0; j < col; j++) {
                cur |= (grid[i][j] << (col - j - 1));
            }
            res += cur;
        }
        return res;
    }
};
