#include<bits/stdc++.h>;
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head; 
        ListNode* fast = head;
        while (2024) {
            if (n-- && fast) {
                fast = fast -> next;
            }
            else {
                while (fast && fast -> next) {
                    slow = slow -> next;
                    fast = fast -> next;
                }
                if(fast == NULL) return head -> next;
                else if(slow -> next) slow -> next = slow -> next -> next;
                else slow -> next = NULL;
                break;
            }
        }
        return head;
    }
};
