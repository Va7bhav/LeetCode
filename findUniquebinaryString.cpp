#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


class Solution {
    void dfs(int i, vector<string> cur, vector<string> nums, unordered_set<string> s, string& res) {
        
        if (i == nums.size()) {
            string curStr = "";
            for (string s: cur) {
                curStr.append(s);
            }
            if (s.find(curStr) ==  s.end()) {
                res = curStr;
                return;
                
            } else {
                return;
            }
        }

        cur[i] = "0";
        dfs(i + 1, cur, nums, s, res);

        cur[i] = "1";
        dfs(i + 1, cur, nums, s, res);
        

        
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> s;
        s.insert(nums.begin(), nums.end());
        vector<string> cur(nums.size(), "0"); 
        string res;
        dfs(0, cur, nums, s, res);
        return res;
    }
};

int main() {
    
    return 0;
}