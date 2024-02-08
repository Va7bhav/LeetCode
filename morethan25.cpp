#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr {1, 2, 2, 6, 6, 6, 6, 6, 7, 10};
    int left = *lower_bound(arr.begin(), arr.end(), 6);
    auto iter = arr.begin();
    cout << *iter;
    iter += 1;
    cout << *iter;
    // cout << left << endl;
    return 0;
}