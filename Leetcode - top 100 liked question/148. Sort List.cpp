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
    ListNode *mergeList(ListNode* h1, ListNode* h2) {
        if(!h1) return h2;
        if(!h2) return h1;
        ListNode *head = NULL, *node = NULL;
        if(h1->val<h2->val) {
            head = h1;
            h1=h1->next;
        } else {
            head = h2;
            h2=h2->next;
        }
        node = head;
        while(h1 && h2) {
            if(h1->val<h2->val) {
                node->next = h1;
                node = node->next;
                h1=h1->next;
            } else {
                node->next = h2;
                node = node->next;
                h2=h2->next;
            }
        }
        if(h2) node->next = h2;
        if(h1) node->next = h1;
        return head;
    }
    
    ListNode *getMid(ListNode *head) {
        if(head==NULL || head->next == NULL) return head;
        ListNode *slow=head, *fast=head->next;
        while(fast) {
            if(fast==NULL || fast->next == NULL) return slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *mid=NULL, *tmp=NULL;
        mid = getMid(head);
        tmp = mid->next;
        mid->next = NULL;
        ListNode *l = sortList(head);
        ListNode * r = sortList(tmp);
        return mergeList(l, r);
    }
};
