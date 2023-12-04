#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = *max_element(nums.begin(), nums.end());
        int currMin = 1, currMax = 1;
        for (auto n : nums) {
            if (n == 0) {
                currMin = 1, currMax = 1;
                continue;
            }
            currMax = max({n, currMax, currMin});
            currMin = min({n, currMax, currMin});
            res = max(res, currMax);
        }
        return res;
    }
};

int main() {
    
    return 0;
}