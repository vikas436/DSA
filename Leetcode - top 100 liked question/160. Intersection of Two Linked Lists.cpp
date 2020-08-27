/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode *head) {
        int cnt=0;
        while(head!=NULL) {
            head= head->next;
            cnt++;
        }
        return cnt;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = length(headA);
        int lenB = length(headB);
        int diff=0;
        if(lenA>lenB) {
            diff = lenA-lenB;
            while(diff!=0) {
                headA=headA->next;
                diff--;
            }
        } else {
            diff = lenB-lenA;
            while(diff!=0) {
                headB=headB->next;
                diff--;
            }
        }
        while(headA!=NULL && headB!=NULL) {
            if(headA==headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
