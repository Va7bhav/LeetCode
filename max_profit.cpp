#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            min_price = min(min_price, prices[i]);
            max_profit = max(max_profit, prices[i] - min_price);
        }
        return max_profit;
    }
};


int main(){
    vector<int> prices = {7,1,5,3,6,4};
    Solution sally;
    int ans = sally.maxProfit(prices);
    cout<<ans;

    return 0;
}