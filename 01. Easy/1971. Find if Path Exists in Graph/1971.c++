class Solution {
private:
    void dfs(int node, vector<vector<int>>& g, vector<bool>& vis) {
        vis[node] = true;
        for(auto &child : g[node]) {
            if(!vis[child]) dfs(child, g, vis);
        }
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> vis(n, false);

        vector<vector<int>> g(n);
        for(auto &it : edges) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }

        dfs(source, g, vis);
        return vis[source] && vis[destination];
    }
};
