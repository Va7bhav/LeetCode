#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD = 1e9 + 7;

class Job {
    public:
    int start;
    int end;
    int prof;
};

bool sortByStart(Job& a, Job& b) {
    if (a.start == b.start) {
        return a.end < b.end;
    }
    return a.start < b.start;
}
class Solution {
    int f(int i, vector<Job> J, vector<int> dp) {
        if (i == J.size()) {
            return 0;
        }
        if (dp[i] != -1) return dp[i];

        // not take
        int res = f(i + 1, J, dp);

        // take
        
        // int j = i + 1;
        // look for a j where starting of J[j].start is >= J[i].end
        // while (j < n && J[j].start < J[i].end) {
        //     j += 1;
        // }
        int l = i + 1, r = J.size(); 
        while (l <= r) {
            int m = (l + r) << 1;
            if (J[m].start < J[i].end) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        int j = r;
        res = max(res, J[i].prof + f(j, J, dp));

        return dp[i] = res;
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<Job> J(n);
        
        for (int i = 0; i < profit.size(); i++) {
            J[i].start = startTime[i];
            J[i].end = endTime[i];
            J[i].prof = profit[i];
        }
        
        sort(J.begin(), J.end(), sortByStart);
        vector<int> dp(profit.size(), -1);
        return f(0, J, dp);
    }
};

int main() {
    
    return 0;
}