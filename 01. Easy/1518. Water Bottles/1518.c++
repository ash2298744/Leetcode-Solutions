class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0, empty = 0;
        while(numBottles) {
            numBottles--;
            empty++;
            res++;
            if(empty == numExchange) {
                numBottles++;
                empty = 0;
            }
        }
        return res;
    }
};
