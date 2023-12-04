#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 2;
        int m;
        while(l <= r) {
            if(m % 2 != 0 && nums[m + 1] != nums[m]) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
            int m = l + (r - l) / 2;
        }
        return nums[l];
    }
};

int main() {
    
    return 0;
}