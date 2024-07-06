class Solution {
public:
    int passThePillow(int n, int time) {
        int curr = 1, turn = 1;
        while(time) {
            if(turn) {
                while(time && curr < n) {
                    curr++;
                    time--;
                }
            } else {
                while(time && curr > 1) {
                    curr--;
                    time--;
                }
            }
            turn ^= 1;
        }
        return curr;
    }
};
