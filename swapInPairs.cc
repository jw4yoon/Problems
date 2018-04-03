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
    ListNode* swapPairs(ListNode* head) {
        ListNode * travel;
        travel = head;
        bool initial = true;
        ListNode * tmp;
        if (travel == nullptr) { // head is empty
            return head;
        }
        
        while(true) {
            if (!initial && travel->next == nullptr) {
                break;
            }
            if (!initial && travel->next->next == nullptr) {
                break;
            }
            tmp = travel->next;
            if (initial && travel->next == nullptr) {
                break;
            }
            if (initial) {
                tmp = travel;
                head = travel->next;
                tmp->next = head->next;
                head->next = tmp;
                travel = head->next;
                initial = false;
            } else if (!initial) {
                travel->next = travel->next->next;
                travel = travel->next;
                if (initial) {
                    head = travel;
                    initial = false;
                }
                tmp->next = travel->next;
                travel->next = tmp;
                travel = travel->next;
            }
        }
        return head;
    }
};
