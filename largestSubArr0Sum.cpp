#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>& nums, int n) { 
        map<int, int> hash;
        int sum = 0;
        int maxLen = 0; 
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == 0) {
                maxLen = i + 1;
            }
            else {
                if(hash.find(sum) != hash.end()) {
                    maxLen = max(maxLen, i - hash[sum]);
                } 
                else {
                    hash[sum] = i;
                }
            }
        }
        return maxLen;
    }
};


int main() {
    vector<int> nums {1, -1, 3, 2, -2, -8, 1, 7, 10, 23};
    Solution sally;
    cout << sally.maxLen(nums, 0);
    return 0;
}