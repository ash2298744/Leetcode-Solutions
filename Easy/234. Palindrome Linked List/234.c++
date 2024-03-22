/**
 * Definition for singly-linked list.
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
    bool dfs(ListNode* node, ListNode* &curr) {
        if(node == NULL) return true;
        if(!dfs(node -> next, curr)) return false;
        if(curr -> val != node -> val) return false;
        curr = curr -> next;
        return true;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        return dfs(head, curr);
    }
    
};