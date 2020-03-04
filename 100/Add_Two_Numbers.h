#include<header.h>

//Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;
        ListNode* head = NULL;
        int result = 0;
        int forward = 0;
        while(l1&&l2){
            result = ( l1->val + l2->val  + forward ) % 10;
            forward = ( l1->val + l2->val + forward ) / 10;
            ListNode* temp = new ListNode(result);
            if ( head ) {
                res->next = temp;
                res = temp;
            } else {
                res = temp;
                head = res;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 || l2){
            ListNode* t = (!l1)?l2:l1;
            while(t){
                result = (t->val + forward) % 10;
                forward = (t->val + forward) /10;
                ListNode* temp = new ListNode(result);
                res->next = temp;
                res = temp;
                t = t->next;
            }
        }
        if(forward){
            res->next = new ListNode(forward);
        }
        return head;
    }
};