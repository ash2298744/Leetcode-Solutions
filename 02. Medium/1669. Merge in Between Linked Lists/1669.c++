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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        b = b - a-- + 1;
        
        ListNode *curr1 = list1;
        while(a--) curr1 = curr1 -> next;

        ListNode *curr2 = curr1;
        while(b--) curr2 = curr2 -> next;

        curr1 -> next = list2;
        while(curr1 -> next) curr1 = curr1 -> next;
        curr1 -> next = curr2 -> next;
        return list1;
    }
};

