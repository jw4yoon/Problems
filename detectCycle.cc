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
    while(node != nullptr) {// move node twice when node2 moves 1
        node = node->next;
        if (node == nullptr) {
            break;
        }
        node = node->next;
        node2 = node2->next; 
        if (node == node2) {
            return true;
        }
    }
    return false;
}
