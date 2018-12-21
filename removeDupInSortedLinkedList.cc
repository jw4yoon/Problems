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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* result = head;
        if (result == nullptr) {
            return result;
        }
        ListNode* traverse = head;
        while(traverse->next != nullptr) {
            if (traverse->val == traverse->next->val) {
                ListNode* nodeToDelete = traverse->next;
                traverse->next = traverse->next->next;
                delete nodeToDelete;
            } else {
                traverse = traverse->next;
            }
        }
        return result;
    }
};
