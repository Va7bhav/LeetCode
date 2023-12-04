#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int mid = -1;
        while(left<=right) {
            mid = left + (right-left)/2;
            if(nums[mid] > target) {
                if(target >= nums[left]) {
                    right = mid - 1; 
                }
                else if (target < nums[left]) {
                    left = mid + 1;
                }   
            }
            else if(nums[mid] < target) {
                if(target <= nums[right]) {
                    left = mid + 1;
                }
                else if(target > nums[right]) {
                    right = mid - 1;
                }
            }
            else if(nums[mid] == target){
                return mid;
            }
        }
        return -1;
    }
};
int main() {
    Solution sally;
    vector<int> vec {4, 5, 6, 7, 8, 9, 0, 1, 2};
    cout<<sally.search(vec, 9);  
    return 0;
}