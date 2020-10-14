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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        int sum=0, carry=0,x=0,y=0;
        ListNode *node = NULL, *ptr=NULL;
        while(l1 || l2) {
            if(l1) x = l1->val;
            if(l2) y = l2->val;
            sum=x+y+carry;
            carry = sum / 10;
            sum = sum % 10;
            if(!node) {
                node = new ListNode(sum);
                ptr=node;
            } else {
                node->next = new ListNode(sum);
                node=node->next;
            }
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            x=y=0;
        }
        if(carry) node->next = new ListNode(carry);
        return ptr;
    }
};
