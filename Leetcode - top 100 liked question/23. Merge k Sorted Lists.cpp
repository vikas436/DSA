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
    struct compare {
    bool operator()(
        struct ListNode* a, struct ListNode* b)
            {
                return a->val > b->val;
            }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        ListNode* node=NULL, *head=NULL;
        priority_queue <ListNode*, vector<ListNode*>, compare> pq;
        for(int i=0;i<lists.size();i++) {
            if(lists[i])
                pq.push(lists[i]);
        }
        while(!pq.empty()) {
            ListNode* tmp = pq.top();
            cout<<tmp->val<<" ";
            pq.pop();
            if(head==NULL) {
                head = new ListNode(tmp->val);
                node = head;
            } else {
                head->next = new ListNode(tmp->val);
                head = head->next;
            }
            if(tmp->next) pq.push(tmp->next);
        }
        return node;
    }
};
