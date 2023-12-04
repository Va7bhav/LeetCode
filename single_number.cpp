#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        for(int i = 0; i < ((nums.size())/2 + 1); i+=2) {
            if(nums[i] != nums[i+1]){
                return nums[i];
            }
        }
        return nums[nums.size() - 1];
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=2)
        {
            if(nums[i]!=nums[i-1])
                return nums[i-1];
        }
        return nums[nums.size()-1];
    }
};


class Solution {
public:
    int singleNumber(vector<int>& nums) { 
        int res = 0                 ;
        for(auto i : nums){
            res = res ^ i;
        }
        
        return res;
    }
};
int main() {
    Solution sally;
    vector<int> vec = {2,2,1};
    int ans = sally.singleNumber(vec);
    cout<<ans;
    return 0;
}