#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// class Solution {
//     int f(int i, int k, string target, vector<string>& words ,vector<vector<int>>& dp) {
//         if (i == target.length()) {
//             return 1;
//         }
//         if (k == words[0].length()) {
//             return 0;
//         }

//         if (dp[i][k] != -1) return dp[i][k];
        
//         int res = 0;

//         // not take
//         res += f(i, k + 1, target, words ,dp); 

//         // take 
//         for (string word: words) {
//             if (word[k] == target[i]) {    
//                 res += f(i + 1, k + 1, target, words ,dp);
//             }
// //         }
// //         return dp[i][k] = res;
// //     }
// // public:
// //     int numWays(vector<string>& words, string target) {
// //         vector<vector<int>> dp(target.length(vector<int> (words[0].length(), -1));
// //         return f(0, 0, target, words ,dp);
// //     }
// };


int main() {
    cout << pow(10, 2);
    return 0;
}