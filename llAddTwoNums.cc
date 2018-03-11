/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// adding two numbers in reverse order
// ex. Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807
class addTwoNums {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        int carry = 0;
        ListNode* move = result;
        while(l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                move->val += l2->val;
                l2 = l2->next;
            } else if (l2 == nullptr) {
                move->val += l1->val;
                l1 = l1->next;
            } else {
                move->val += l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            if (move->val >= 10) {
                carry = 1;
                move->val -= 10;
            }
            if (l1 != nullptr || l2 != nullptr || carry == 1) {
                move->next = new ListNode(0);
                move->next->val += carry;
                carry = 0;
            }
            move = move->next;
        }
        return result;
    }
};

