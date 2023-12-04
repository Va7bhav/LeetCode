#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int nTotal = (n + rolls.size()) * mean - accumulate(rolls.begin(), rolls.end(), 0);

        vector<int> res = {};
        if (nTotal < n || nTotal > 6*n) {
            return res;
        }

        // at anytimes nTotal could not be lesser then n
        while (n) {
            int dice = min(nTotal - n + 1, 6);
            res.push_back(dice);
            nTotal -= dice;
            n -= 1;
        }

        return res;
    }
};

int main() {
    
    return 0;
}