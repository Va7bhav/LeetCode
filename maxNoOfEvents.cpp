#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


bool comp(vector<int>& p1, vector<int>& p2) {
    if (p1[1] == p2[1]) return p1[0] < p2[0];
    return p1[1] < p2[1]; 
}

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), comp);

        int d = 1;
        int res = 0;
        for (int i = 0; i < events.size(); i++) {
            while (d <= events[i][1]) {
                d = events[i][1];
                i += 1;
                res += 1;
            }
        }
        return res;
    }

    
};

int main() {
    
    return 0;
}