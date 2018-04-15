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

int number_needed(string a, string b) {
    int aLen = a.length();
    int bLen = b.length();
    map<char, int> aDict;
    map<char, int> bDict;
    int count = 0;
    for (int i = 0; i < aLen; ++i) {
        aDict[a[i]] += 1;
    }
    for (int i = 0; i < bLen; ++i) {
        bDict[b[i]] += 1;
    }
    for (auto it=aDict.begin(); it!=aDict.end(); ++it) {
        if (bDict.find(it->first) != bDict.end()) {
            if (bDict[it->first] > it->second) {
                count += it->second;
            } else {
                count += bDict[it->first];
            }
        }
    }
    return (aLen - count) + (bLen - count);
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
