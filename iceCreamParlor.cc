#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

void solve(vector <int> arr, int money) {
    map<int, int> myMap;
    int arrSize = arr.size();

    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] <= money) {
            if (myMap.find(arr[i]) != myMap.end()) {
                int target = myMap[arr[i]];
                if (arr[i] * 2 == money) {
                    if (target < i) {
                        cout << target + 1 << " " << i + 1 << endl;
                    } else {
                        cout << i + 1 << " " << target + 1  << endl;
                    }
                    return;
                }
            } else {
                myMap[arr[i]] = i;
            }
        }
    }
    for (int i = 0; i < arrSize; ++i) {
        if (myMap.find(money - arr[i]) != myMap.end()) {
            int tar = myMap[money - arr[i]];
            if (tar < i) {
                cout << tar + 1 << " " << i + 1 << endl;
            } else {
                cout << i + 1 << " " << tar + 1 << endl;
            }
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int money;
        cin >> money;
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        solve(arr, money);
    }
    return 0;
}


