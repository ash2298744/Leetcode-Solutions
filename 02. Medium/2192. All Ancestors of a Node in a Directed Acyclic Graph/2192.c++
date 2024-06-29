class Solution {
public:
    void dfs(int node, vector<vector<int>>& g, set<int>& nodesAncs) {
        for(int i : g[node]) {
            if(!nodesAncs.count(i)) {
                nodesAncs.insert(i);
                dfs(i, g, nodesAncs);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(int i = 0; i < edges.size(); i++) {
            g[edges[i][1]].push_back(edges[i][0]);
        }

        vector<vector<int>> ancs;
        for(int i = 0; i < n; i++) {
            set<int> nodesAncs;
            dfs(i, g, nodesAncs);
            vector<int> curr(nodesAncs.begin(), nodesAncs.end());
            ancs.push_back(curr);
        }
        return ancs;
    }
};
