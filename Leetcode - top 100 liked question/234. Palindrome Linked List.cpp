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
    int length(ListNode* head) {
        int cnt = 0;
        while(head!=NULL) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    
    ListNode *reverse(ListNode *head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode * ret = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return ret;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode *start = head, *rev=NULL,*pre=NULL;
        int len = length(head);
        int num = len/2;
        if(len%2==0) {
            num--;
            while(num>0 && head!=NULL) {
                head = head->next;
                num--;
            }
            rev = reverse(head->next);
            head->next=NULL;
        } else {
            while(num>0 && head!=NULL) {
                pre=head;
                head = head->next;
                num--;
            }
            pre->next=NULL;
            rev = reverse(head->next);
        }
        
        while(start!=NULL && rev!=NULL) {
            if(start->val!=rev->val) return false;
            start = start->next;
            rev = rev->next;
        }
        return true;
    }
};
