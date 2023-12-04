#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals. begin(), intervals.end());
        int res = 0;
        int prevEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= prevEnd) {
                prevEnd = intervals[i][1];
            }
            else {
                res += 1;
                prevEnd = min(prevEnd, intervals[i][1]);
            }
        }
        return res;
    }
};
int main() {
    
    return 0;
}