#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end()); 

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;

        unordered_map<int, int> hash;
        vector<int> res(queries.size());

        int ind = 0;
        vector<int> qs (queries.begin(), queries.end());
        sort(qs.begin(), qs.end());
        for (int q: qs) {
            while (!minH.empty() && q > minH.top().second) { // pop
                minH.pop();
            }
            while (ind < intervals.size() && q >= intervals[ind][0]) {
                int length = intervals[ind][1] - intervals[ind][0] + 1;
                minH.push({length, intervals[ind][1]});
                ind += 1;
            } 


            // cout << q << " " << hash[q] << endl;
            if (minH.empty()) res[hash[q]] = -1;
            else {
                pair<int, int> apex = minH.top();
                hash[q] = apex.first;
            }
        }
        vector<int> res;
        for (int q: queries) {
            res.push_back(hash[q]);
        }
        return res;
    }
};

int main() {
    
    return 0;
}