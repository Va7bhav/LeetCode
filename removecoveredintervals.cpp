#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    struct s {
        int pos;
        int start;
        int end;
    };
    bool lambda(struct s i1, struct s i2) {
        // if (i1.start == i2.start) {
        //     return i1.end >= i2.end;
        // }
        // else return (i1.start <= i2.start);
        return i1.start < i2.start;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        struct s in[10];
        for (int i = 0; i < intervals.size(); i++) {
            in[i].pos = i + 1;
            in[1].start = intervals[i][0];
            in[1].end = intervals[i][1];
        }
        // sort(intervals.begin(), intervals.end(), lambda);
    }
};

int main() {
    Solution sally;
    vector<vector<int>> intervals {{1, 4}, {3, 6}, {2, 8}, {2, 7}, {2, 4}};
    sally.removeCoveredIntervals(intervals);
    for (int i = 0; i < intervals.size(); i++) {
        cout << intervals[i][0] << "," << intervals[i][1] << endl;
    }
    return 0;
}