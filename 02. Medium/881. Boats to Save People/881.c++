class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end()); // solve greedily after sorting

        int boats = 0, left = 0, right = people.size() - 1;
        while(left <= right) {
            int onTheBoat = people[left] + people[right];

            if(left == right)
                onTheBoat -= people[right]; // to remove duplicate weight

            if(onTheBoat > limit) right--; // we can always exclude the largest weight if more than limit. (since, limit >= people[i])
            else left++, right--;
            boats++;
        }
        return boats;
    }
};
