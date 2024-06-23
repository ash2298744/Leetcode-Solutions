class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int val1 = 0, val2 = 0, c1 = 0, c2 = 0;
        for(int i = 0; i < player1.size(); i++) {
            if(c1 > 0) {
                val1 += 2 * player1[i];
                c1--;
            } else val1 += player1[i];
            
            if(c2 > 0) {
                val2 += 2 * player2[i];
                c2--;
            } else val2 += player2[i];

            if(player1[i] == 10) c1 = 2;
            if(player2[i] == 10) c2 = 2;
        }
        if(val1 > val2) return 1;
        if(val1 < val2) return 2;
        return 0;
    }
    
};
