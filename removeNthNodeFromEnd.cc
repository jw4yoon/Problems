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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur = head;
        ListNode *travel = head;
        while (true) {
            for (int i = 0; i < n; ++i) { // move travel by n step
                travel = travel->next;
            }
            if (travel == nullptr) { // if travel reached the end, remove the original head
                head = cur->next;
                delete cur;
                break;
            }
            else if (travel->next == nullptr) { // when trave->next == nullptr(end), cur->next is nth node from end so remove
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                break;
            }
            cur = cur->next;
            travel = cur;
        }
        return head;
    }
};
