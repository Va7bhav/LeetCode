#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) {
            return intervals;
        }
        if(intervals.size() == 1) {
            return intervals;
        }
        
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        vector<int> temp;

        temp = intervals[0];

        for(auto it : intervals) {
            if(temp[1] >= it[0]) {
                temp[1] = max(it[1], temp[1]);
            }
            else {
                ans.push_back(temp);
                temp = it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};

int main() {


    return 0;
}