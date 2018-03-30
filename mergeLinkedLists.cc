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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l1Move = l1;
        ListNode *l2Move = l2;
        ListNode *result;
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        if (l1Move->val <= l2Move->val) {
            result = l1Move;
            l1Move = l1Move->next;
        } else if (l2Move->val < l1Move->val) {
            result = l2Move;
            l2Move = l2Move->next;
        }
        ListNode *resultMove = result;
        
        while(true) {
            if (l1Move == NULL) {
                resultMove->next = l2Move;
                return result;
            } else if (l2Move == NULL) {
                resultMove->next = l1Move;
                return result;
            } else if (l1Move->val <= l2Move->val) {
                resultMove->next = l1Move;
                resultMove = resultMove->next;
                l1Move = l1Move->next;
            } else if (l2Move->val < l1Move->val) {
                resultMove->next = l2Move;
                resultMove = resultMove->next;
                l2Move = l2Move->next;
            }
        }
        return result;
    }
};
