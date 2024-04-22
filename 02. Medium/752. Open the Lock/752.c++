class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<char, vector<char>> move = {
            {'0', {'1', '9'}},
            {'1', {'2', '0'}},
            {'2', {'3', '1'}},
            {'3', {'4', '2'}},
            {'4', {'5', '3'}},
            {'5', {'6', '4'}},
            {'6', {'7', '5'}},
            {'7', {'8', '6'}},
            {'8', {'9', '7'}},
            {'9', {'0', '8'}}
        };

        unordered_set<string> vis;
        for(auto &ss : deadends) vis.insert(ss);

        if(vis.count("0000")) return -1;
        vis.insert("0000");

        queue<pair<string, int>> q;
        q.push({"0000", 0});
        while(!q.empty()) {
            string s = q.front().first;
            int turns = q.front().second;
            q.pop();

            if(s == target) return turns;

            for(int i = 0; i < 4; i++) {
                char temp = s[i];
                for(auto &j : move[temp]) {
                    s[i] = j;
                    if(!vis.count(s)) {
                        vis.insert(s);
                        q.push({s, turns + 1});
                    }
                    s[i] = temp;
                }
            }
        }
        return -1;
    }
};
