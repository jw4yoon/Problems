#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Node { // multiway tries, my dictionary
	char character;
	int directChild = 0;
    int totalChild = 0;
	vector<Node*> children;
};

int find(Node* cur, string contact) {
    bool charExist = false;
    int index = 0;
    int toReturn = 0;
    if (contact == "") {
        toReturn = cur->totalChild;
    } else {
        for (int i = 0; i < cur->directChild; ++i) {
            if (cur->children[i]->character == contact[0]) {
                charExist = true;
                index = i;
                break;
            }
        }
        if (charExist) {
            toReturn = find(cur->children[index], contact.substr(1));
        } else {
            toReturn = 0;
        }
    }
    return toReturn;
}

void add(Node* cur, string contact) {
    bool charExist = false;
    int index = 0;
    if (contact == "") {
        Node* child = new Node{};
        child->character = ' ';
        cur->children.push_back(child);
        cur->directChild += 1;
        cur->totalChild += 1;
        return;
    } else if (cur->directChild == 0) {
        Node* child = new Node {};
        child->character = contact[0];
        cur->children.push_back(child);
        cur->directChild += 1;
        cur->totalChild += 1;
        add(cur->children.back(), contact.substr(1));
    } else {
        for (int i = 0; i < cur->directChild; ++i) {
            if (cur->children[i]->character == contact[0]) {
                charExist = true;
                index = i;
                break;
            }
        }
        if (charExist) {
            cur->totalChild += 1;
            add(cur->children[index], contact.substr(1));
        } else {
            Node* child = new Node{};
            child->character = contact[0];
            cur->children.push_back(child);
            cur->directChild += 1;
            cur->totalChild += 1;
            add(cur->children.back(), contact.substr(1));
        }
    }
}

int main(){
    int n;
    cin >> n;
    int printout = 0;
    Node* head = new Node{};
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if (op == "add") {
            add(head, contact);
        } else if (op == "find") {
            printout = find(head, contact);
            cout << printout << endl;
        }
    }
    return 0;
}


