class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int row = land.size(), col = land[0].size();
        vector<vector<int>> ans, dircn = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(land[i][j]) {
                    pair<int, int> curr = {i, j};
                    deque<pair<int, int>> q;
                    q.push_front({i, j});
                    while(!q.empty()) {
                        int x = q.front().first, y = q.front().second;
                        q.pop_front();
                        for(int k = 0; k < 4; k++) {
                            int ii = x + dircn[k][0];
                            int jj = y + dircn[k][1];
                            if(ii < 0 || jj < 0 || ii == row || jj == col || land[ii][jj] == 0) {
                                continue;
                            } 
                            land[ii][jj] = 0;
                            curr = max(curr, {ii, jj});
                            q.push_back({ii, jj});
                        }
                    }
                    ans.push_back({i, j, curr.first, curr.second});
                }
            }
        }
        return ans;
    }
};
  