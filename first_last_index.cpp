#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        int first_index, last_index;
        int ptr;
        while(left <= right) {
            mid = left + (right - left)/2;
            if(nums[mid] == target) {
                ptr = mid;
                while(nums[ptr] == nums[mid]) {
                    ptr--;
                }
                first_index = ptr + 1;

                ptr = mid;
                while(nums[ptr] == nums[mid]) {
                    ptr++;
                }
                last_index = ptr - 1;
                break;
            }      
            else if (nums[mid] < target) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        if(left <= right) {
            vector<int> ans {first_index, last_index};
            return ans;
        }
        else {
            vector<int> ans {-1, -1};
            return ans;
        }
    }
};    

class Solution2 {
private: 
    int binarySearch_firstIndex(vector<int> arr, int target) {
        int left = 0;
        int right = arr.size()-1;
        int mid;
        int ans = -1;
        while(left <= right) {
            mid = left + (right - left)/2;
            if(arr[mid] == target) {
                ans = mid;
                right = mid-1;
            }      
            else if (arr[mid] < target) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return ans;
    }
    int binarySearch_lastIndex(vector<int> arr, int target) {
        int left = 0;
        int right = arr.size()-1;
        int mid;
        int ans = -1;
        while(left <= right) {
            mid = left + (right - left)/2;
            if(arr[mid] == target) {
                ans = mid;
                left = mid+1;
            }      
            else if (arr[mid] < target) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstIndex = binarySearch_firstIndex(nums, target);
        int lastIndex = binarySearch_lastIndex(nums, target);
        vector<int> ans {firstIndex, lastIndex};
        return ans;
    }
};   
int main() {
    Solution sally;
    vector<int> nums {1};
    vector<int> ans = sally.searchRange(nums, 1);
    cout<<ans[0];
    cout<<ans[1];
    return 0;
}
