#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int> st;
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[i] < 0 && st.back() > 0) {
                int diff = st.back() + nums[i];
                if (diff < 0) {
                    st.pop_back();
                }
                else if (diff > 0) {
                    nums[i] = 0;
                }
                else {
                    nums[i] = 0;
                    st.pop_back();
                }
            }
            if (nums[i] > 0) {
                st.push_back(nums[i]);
            }
        }
    return st;
    }
};
int main() {
    
    return 0;
}