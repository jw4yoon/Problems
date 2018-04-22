/*
A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    Node* node = head;
    Node* node2 = head;
    bool moveNode2 = false;
    while(node != nullptr) {
        if (moveNode2) { // 
            node2 = node2->next;
        }
        node = node->next;
        if (node == node2) {
            return true;
        }
        moveNode2 = !moveNode2; // to move node2 only once when node moves twice
    }
    return false;
}
