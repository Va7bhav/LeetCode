#include<iostream>
#include<vector>
using namespace std;

// basic recursion
int f(int n, int w, vector<int> weight, vector<int> value) {
    if(n == -1) { 
        return 0;
    }
    int not_take = 0 + f(n - 1, w, weight, value);
    int take = -1;
    if(weight[n] <= w) {
        take = value[n] + f(n-1, w - weight[n], weight, value);
    }
    return max(take, not_take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    return f(value.size() - 1, maxWeight, weight, value);
}

// int f(int n, int w, vector<int> weight, vector<int> value) {
//     if(n == 0) { 
//         if(weight[0] <= w) return value[0];
//         else return 0;
//     }
//     int not_take = 0 + f(n - 1, w, weight, value);
//     int take = -1;
//     if(weight[n] <= w) {
//         take = value[n] + f(n-1, w - weight[n], weight, value);
//     }
//     return max(take, not_take);
// }
// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
//     return f(value.size() - 1, maxWeight, weight, value);
// }

// memory optimisation
// int f(int n, int w, vector<int> weight, vector<int> value, vector<vector<int>> dp) {
//     if(n == 0) { 
//         if(weight[0] <= w) return value[0];
//         else return 0;
//     }
//     if(dp[n][w] != -1) return dp[n][w];
//     int not_take = 0 + f(n - 1, w, weight, value, dp);
//     int take = -1;
//     if(weight[n] <= w) {
//         take = value[n] + f(n-1, w - weight[n], weight, value, dp);
//     }
//     dp[n][w]  = max(take, not_take);
//     return dp[n][w];
// }
// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
//     vector<vector<int>> dp (n, vector<int> (maxWeight + 1, -1));
//     return f(n - 1, maxWeight, weight, value, dp);
// }

//tabulation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<vector<int>> dp (n, vector<int> (maxWeight + 1));
    for(int w = 0; w <= maxWeight; w++) dp[0][w] = value[0];

    for(int i = 1; i <= n - 1; i++) {
        for(int w = 0; w <= maxWeight; w++) {
            int not_take = 0 + dp[i - 1][w];
            int take = INT_MIN;
            if(weight[n] <= w) {
                take = value[n] + dp[n - 1][w - weight[n]];
            }
            dp[n][w] = max(take, not_take);
        }
    }
    return dp[n - 1][maxWeight];
}
// space optimisation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<int> prev (maxWeight + 1);   
    vector<int> curr (maxWeight + 1);
    for(int w = weight[0]; w <= maxWeight; w++) prev[w] = value[0];

    for(int i = 1; i < n ; i++) {
        for(int w = 0; w <= maxWeight; w++) { 
            int not_take = 0 + prev[w];
            int take = INT_MIN;
            if(weight[n] <= w) {
                take = value[n] + prev[w - weight[n]]; // here the second variable is dependent on the previous row
            }
            curr[w] = max(take, not_take);
        }
        prev = curr;
    }
    return prev[maxWeight];
}

// 1-d Array space-optimised
// when the second variable is dependent on the previous row
// and the and in the previous row the previous indexes are required 
// https://youtu.be/GqOmJHQZivw?t=2348
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<int> prev (maxWeight + 1);   
    for(int w = weight[0]; w <= maxWeight; w++) prev[w] = value[0];

    for(int i = 1; i < n ; i++) {
        for(int w = maxWeight; w >= 0; w--) { 
            int not_take = 0 + prev[w];
            int take = INT_MIN;
            if(weight[n] <= w) {
                take = value[n] + prev[w - weight[n]]; // here the second variable is dependent on the previous row
            }
            prev[w] = max(take, not_take);
        }
    }
    return prev[maxWeight];
}
int main() {
    cout << knapsack({3, 2, 5}, {30, 40, 60}, 3, 6);
    return 0;                               
}