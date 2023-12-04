#include<iostream>
#include<vector>
using namespace std;
class Solution {
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
        cout<<firstIndex<<","<<lastIndex<<endl;
        vector<int> ans {firstIndex, lastIndex};
        return ans;
    }
};      

int main() {
    Solution sally;
    vector<int> nums = {1, 2, 3, 3, 3, 3, 5};
    vector<int> ans;
    ans = sally.searchRange(nums, 3);
    cout<<ans[0];
    cout<<ans[1];
    return 0;
}