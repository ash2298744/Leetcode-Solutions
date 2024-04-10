class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size() - 1;
        sort(deck.begin(), deck.end());
        deque<int> ans;
        
        ans.push_front(deck[n--]);
        while(n >= 0) {
            int temp = ans.back();
            ans.pop_back();
            ans.push_front(temp);
            ans.push_front(deck[n--]);
        }

        vector<int> res;
        while(!ans.empty()) {
            res.push_back(ans.front());
            ans.pop_front();
        }
        return res;
    }
};
