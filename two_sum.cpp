#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution{
    public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // this method is for sorted vector in argument
         int i = 0;
         int j = (nums.size() - 1);

         sort(nums.begin(), nums.end());

         while(true){
            if(nums[i] + nums[j] != target){
                if(nums[i] + nums[j] < target){
                    i++;
                }
                else if(nums[i] + nums[j] > target){
                    j--;
                }
             }
             else{
                break;
             }
         }

         vector<int> ans(2);
         ans[0] = i;
         ans[1] = j;
         return ans;
    }

    vector<int> twoSum2(vector<int>& nums, int target) {
        map<int, int> hash;
        int i = 0;

         while(true){
            if(hash.find(target - nums[i]) == hash.end()) {
                hash.insert({nums[i], i});
                i++;
            }
                break;
         }
         
         vector<int> ans(2);
         ans[0] = hash[target - nums[i]];
         ans[1] = i;
         return ans;
    }
};
int main(){
    Solution sally;
    vector<int> vec {3,2,4};
    vector<int> ans(2);
    ans = sally.twoSum2(vec, 6);
    cout<<"answer matrix :"<<endl;
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}