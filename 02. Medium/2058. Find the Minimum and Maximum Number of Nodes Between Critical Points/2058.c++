/**
 * Definition for singly-linked list -> 
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *curr = head -> next, *prev = head;
        int first = -1, last = -1, idx = 2, mi = INT_MAX, mx = INT_MIN;
        while(curr -> next) {
            if(((curr -> val < prev -> val and curr -> val < curr -> next -> val) or (curr -> val > prev -> val and curr -> val > curr -> next -> val))) {
                if(first == -1) first = idx;
                if(last != -1) {
                    mi = min(mi, idx - last);
                    mx = max(mx, idx - first);
                }
                last = idx;
            }
            prev = curr;
            curr = curr -> next;
            idx++;
        }

        if(first != last) {
            return {mi, mx};
        }
        return {-1, -1};
    }
};
