/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// adding two numbers in reverse order
// ex. Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->val = 0;
    newNode->next = NULL;
    int carry = 0;
    struct ListNode* move = newNode;
    while (l1 != NULL || l2 != NULL) {
        if (l1 == NULL) {
            move->val += l2->val;
            l2 = l2->next;
        } else if (l2 == NULL){
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
        if (carry != 1 && l1 == NULL && l2 == NULL) {
            break;
        }
        move->next = malloc(sizeof(struct ListNode));
        move = move->next;
        move->val = carry;
        move->next = NULL;
        carry = 0;
    }
    return newNode;
}

