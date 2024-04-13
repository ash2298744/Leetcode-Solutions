class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();

        int dpL[row][col], dpR[row][col];
        memset(dpL, 0, sizeof(dpL));
        memset(dpR, 0, sizeof(dpR));

        for(int i = 0; i < row; i++) {
            dpL[i][0] = matrix[i][0] - '0';
            for(int j = 1; j < col; j++) {
                if(matrix[i][j] == '1') {
                    dpL[i][j] += dpL[i][j - 1] + 1;
                }  
            }
        }
        
        for(int i = 0; i < row; i++) {
            dpR[i][col - 1] = matrix[i][col - 1] - '0';
            for(int j = col - 2; j >= 0; j--) {
                if(matrix[i][j] == '1') {
                    dpR[i][j] += dpR[i][j + 1] + 1;
                } 
            }
        }

        int maxArea = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                int l = col + 1, b = 1, curr = max(dpL[i][j], dpR[i][j]), k = i;
                while(k < row && matrix[k][j] == '1' && max(dpL[i][j], dpR[i][j]) <= curr) {
                    l = min(l, dpR[k][j]);
                    maxArea = max(maxArea, l * b);
                    k++;
                    b++;
                }
            }
        }
        return maxArea;
    }
};
