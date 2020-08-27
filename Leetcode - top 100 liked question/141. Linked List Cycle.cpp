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
    bool hasCycle(ListNode *head) {
        ListNode *null = NULL;
        if(head==null || head->next==null) return false;
        ListNode *fast = head->next;
        while(fast!=null && fast->next!=null) {
            head = head->next;
            fast = fast->next;
            if(fast->next == null) return false;
            fast = fast->next;
            if(head==fast) return true;
        }
        if(fast==null || fast->next==null) return false;
        return true;
    }
};
