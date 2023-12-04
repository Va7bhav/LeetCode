#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> hash;
        for(int n : nums) {
            hash[n]++;
        }
        vector<int> countToValue[7]; 
        for(auto pair : hash) {
            countToValue[pair.second].push_back(pair.first);
        }
        vector<int> res;
        for(int i = nums.size(); i >= 0; i--) {
            for(int ele : countToValue[i]) {
                res.push_back(ele); 
            }
            if(res.size() == k) return res;
        }    
    }  
};

int main() {
    Solution sally;
    vector<int> nums {1,1,1,2,2,3};
    vector<int> res = sally.topKFrequent(nums, 2);
    cout << res[0];
    cout << res[1];
    return 0;
}