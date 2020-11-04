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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return head;
        ListNode *even=head, *odd=head->next, *estr = even ,*ostr=odd;
        head = head->next->next;
        bool turn=true;
        while(head) {
            if(turn) {
                even->next = head;
                even = even->next;
            } else {
                odd->next = head;
                odd = odd->next;
            }
            head = head->next;
            turn = !turn;
        }
        even->next = NULL;
        odd->next = NULL;
        even->next = ostr;
        return estr;
    }
};
