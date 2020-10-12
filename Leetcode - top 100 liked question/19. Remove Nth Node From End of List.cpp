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
    int getLen(ListNode* head) {
        if(head==NULL) return 0;
        return 1 + getLen(head->next);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        int len = getLen(head);
        if(len<n || n<=0) return head;
        int num = len-n;
        if(num==0) {
            return head->next;
        }
        ListNode* node = head, *pre = NULL, *temp=NULL;
        while(num-- > 0) {
            pre = node;
            node = node->next;
        }
        if(node) temp = node->next;
        pre->next = temp;
        return head;
    }
};
