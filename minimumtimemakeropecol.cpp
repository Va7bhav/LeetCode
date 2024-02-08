#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void acc(vector<int>& arr) {accumulate(arr.begin(), arr.end(), 0);}
int MOD = 1e9 + 7;


class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        int l = 0, r = 0;
        while (r < colors.size()) {
            if (colors[l] == colors[r]) {
                if (neededTime[l] < neededTime[r]) {
                    res += neededTime[l]; 
                    l += 1;
                } else {
                    res += neededTime[r];
                }
                r += 1;
            } else {
                l += r, r += 1;
            }
        }        
    }
};

int main() {
    
    return 0;
}