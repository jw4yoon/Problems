class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int numNodes = 0;
        ListNode* traverse = head; // the node that will traverse
        ListNode* originalLastNode; // the lastNode of initial linked list
        while(traverse != nullptr) {
            originalLastNode = traverse;
            ++numNodes;
            traverse = traverse->next;
        }
        if (numNodes <= 1) {
            return head;
        }
        int stepsToRight = k % numNodes;
        if (stepsToRight == 0) {
            return head;
        }
        int headPos = numNodes - stepsToRight; // new head's position(index), starting from 0
        ListNode* originalHead = head;
        traverse = head; //reset traverse
        ListNode* newHead; // will point to new head
        ListNode* nodeBeforeNewHead; // will point to node before newHead to make it point to nullptr
        for (int i = 0; i < headPos - 1; ++i) {
            traverse = traverse->next;
        }
        nodeBeforeNewHead = traverse;
        newHead = traverse->next;
        nodeBeforeNewHead->next = nullptr;
        originalLastNode->next = originalHead;
        return newHead;
        
    }
};
