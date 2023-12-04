#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// int max_repeat_help(vector<int> nums, int i){
//     int max_repeat;
//     int j = i;
//     while(nums[j] == nums[i]){
//         max_repeat = max_repeat + 1;
//         j++;
//     }
//     i = i + max_repeat;
//     return max(max_repeat, max_repeat_help(nums, i));
// }

// int max_repeat(vector<int> nums){
//     sort(nums.begin(), nums.end());
//     int i = 0;
//     return max_repeat_help(nums, i);
    
// }

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority_element;
        int count = 0;

        for (int index_element : nums) {
        
            if(count == 0) majority_element = index_element;

            if(index_element == majority_element) count += 1;

            else count -= 1;
        }
        return majority_element;
    }
};


int main() {
    vector<int> nums {3,2,3};
    Solution sally;
    cout<<sally.majorityElement(nums);
    return 0;
}