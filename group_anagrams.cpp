#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for(auto str : strs) {
            string temp = str;
            sort(str.begin(), str.end());
            hash[str].push_back(temp);
        }
        vector<vector<string>> ans;
        vector<string> temp_list;
        for(auto iter : hash) {
            ans.push_back(iter.second);
        }
        return ans;
    }
};

int main() {
    Solution ellie;
    vector<vector<string>> ans = ellie.groupAnagrams({"eat","tea","tan","ate","nat","bat"});
    return 0;
}