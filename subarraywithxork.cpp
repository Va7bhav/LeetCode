#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD = 1e9 + 7;

int subarraysWithSumK(vector<int> nums, int k) {
    unordered_map<int, int> hash;
    hash[0] = 1;
    int cur = 0;
    int res = 0;
    for (int num: nums) {
        cur ^= num;
        res += hash[cur ^ k];
        hash[cur] += 1;
    }
    return res;
}

int main() {
  
  return 0;
}