/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        Node* node=head;
        while(node) {
            Node* n = new Node(node->val);
            n->next = node->next;
            node->next = n;
            node = node->next->next;
        }
        node=head;
        Node* newNode = head->next,* tmp;
        while(newNode) {
            tmp = node->random;
            if(tmp) {
                newNode->random = tmp->next;
            }
            if(!newNode->next)
                break;
            newNode = newNode->next->next;
            node = node->next->next;
        }
        node=head;
        newNode=head->next;
        tmp = newNode;
        while(node && newNode) {
            if(!newNode->next) {
                node->next = NULL;
                break;
            }
            node->next = node->next->next;
            newNode->next = newNode->next->next;
            newNode = newNode->next;
            node = node->next;
        }
        return tmp;
    }
};
