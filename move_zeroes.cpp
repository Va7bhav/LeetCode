#include<iostream>
#include<vector>
using namespace std;
    class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int l = 0;
            int r = 1; 
            while(r < nums.size()) {
                if(nums[l] != 0){
                    l++;
                }
                if (nums[l]==0 && nums[r]!=0){
                    swap(nums[l], nums[r]);
                }       
                r++;
            }
        }
    };
int main() {
    Solution sally;
    vector<int> vec {0,1,0,3,12};
    sally.moveZeroes(vec);
    cout<<vec[0];
    cout<<vec[1];
    cout<<vec[2];
    cout<<vec[3];
    cout<<vec[4];
    return 0;
}