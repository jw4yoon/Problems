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

bool is_balanced(string expression) {
    int countBig = 0; // []
    int countMed = 0; // {}
    int countSmall = 0; //()
    int sLen = expression.length();
    vector<char> toBeClosed; // stacking left brackets. Top bracket is the one that should be closed first
    for (int i = 0; i < sLen; ++i) {
        if (expression[i] == '[') {
            countBig += 1;
            toBeClosed.push_back('[');
        } else if (expression[i] == '{') {
            countMed += 1;
            toBeClosed.push_back('{');
        } else if (expression[i] == '(') {
            countSmall +=1;
            toBeClosed.push_back('(');
        } else if (expression[i] == ']') {
            if (toBeClosed.empty() || toBeClosed.back() != '[') {
                return false;
            }
            countBig -= 1;
            toBeClosed.pop_back();           
        } else if (expression[i] == '}') {
            if (toBeClosed.empty() || toBeClosed.back() != '{') {
                return false;
            }
            countMed -= 1;
            toBeClosed.pop_back();
        } else if (expression[i] == ')') {
            if (toBeClosed.empty() || toBeClosed.back() != '(') {
                return false;
            }
            countSmall -=1;
            toBeClosed.pop_back();
        }
    }
    if (countBig == 0 && countMed == 0 && countSmall == 0) {
        return true;
    } else {
        return false;
    }
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}


