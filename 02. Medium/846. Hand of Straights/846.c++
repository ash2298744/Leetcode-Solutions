class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        sort(hand.begin(), hand.end());

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) mp[hand[i]]++;

        for(int i = 0; i < hand.size(); i++) {
            if(mp[hand[i]]) {
                int curr = mp[hand[i]];
                for(int j = 0; j < groupSize; j++) {
                    if(mp[hand[i] + j] < curr) return false;
                    mp[hand[i] + j] -= curr;
                }
            }
        }
        return true;
    }
};
