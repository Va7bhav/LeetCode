#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    int f(int i, vector<int>& days, vector<int>& costs) {
        if (i == days.size()) {
            return 0;
        }
        
        int cost = INT_MAX;
        
        cost = min(cost, costs[0] + f(i + 1, days, costs));

        // take seven days pass
        int j = i;
        while (j < days.size() && days[j] < days[i + 7]) {
            j += 1;
        }
        cost = min(cost, costs[1] + f(j, days, costs));
        
        // take thirty days pass
        j = i;
        while (j < days.size() && days[j] < days[i + 30]) {
            j += 1;
        }
        cost = min(cost, costs[2] + f(j, days, costs));

        return cost;
        
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return f(0, days, costs);
    }
};

int main() {
    
    return 0;
}