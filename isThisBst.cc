/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/

bool checkBSTHelper(Node* node, vector<int> &checkDup, int min, int max) {
    if (node == nullptr) {
        return true;
    }
    for (auto it = checkDup.begin() ; it != checkDup.end(); ++it) {
        if (node->data == *it) {
            return false;
        }
    }
    checkDup.push_back(node->data);
    if (min != -1 && node->data < min || max != -1 && node->data > max) {
        return false;
    }
    
    if (!checkBSTHelper(node->left, checkDup, min, node->data) || !checkBSTHelper(node->right, checkDup, node->data, max)) {
        return false;
    }
    return true;
}

bool checkBST(Node* root) {
    if (root == nullptr) {
        return false;
    }
    vector<int> checkDup;
    return checkBSTHelper(root, checkDup, -1, -1);
}
