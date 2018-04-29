#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;   
        void push(int x) {
            if (stack_oldest_on_top.empty()) {
                stack_oldest_on_top.push(x);
            } else {
                stack_newest_on_top.push(x);
            }
        }

        void pop() {
            if (!stack_oldest_on_top.empty()) {
                stack_oldest_on_top.pop();
                if (stack_oldest_on_top.empty()) {
                    int count = 0;
                    int num = 0;
                    while(!stack_newest_on_top.empty()) { //move everything from newest stack to oldest stack
                        ++count;
                        num = stack_newest_on_top.top();
                        stack_oldest_on_top.push(num);
                        stack_newest_on_top.pop();
                    }
                }
            }
        }

        int front() {
            return stack_oldest_on_top.top();
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}


