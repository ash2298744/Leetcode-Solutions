class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), cnt;
        int dpL[row][col], dpR[row][col];

        for(int i = 0; i < row; i++) {
            cnt = 0;
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == '0') cnt = 0;
                else {
                    dpL[i][j] = ++cnt;
                }
            }
        }

        for(int i = 0; i < row; i++) {
            cnt = 0;
            for(int j = col - 1; j >= 0; j--) {
                if(matrix[i][j] == '0') cnt = 0;
                else {
                    dpR[i][j] = ++cnt;
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
