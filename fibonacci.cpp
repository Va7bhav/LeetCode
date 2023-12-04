#include<iostream>
#include<vector>
using namespace std;

// normal
int fib(int n) {
    if(n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

// memoized
int fibm(int n, vector<int> dp) {
    if(n <= 1) {
        return n;
    }
    if(dp[n] != -1) { // step - 3
        return dp[n];
    }
    dp[n] =  fibm(n - 1, dp) + fibm(n - 2, dp); // step - 2
    return dp[n];
}

// tabulated
int fibt(int n, vector<int> dp) {
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i < dp.size(); i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// ultimate
int fibu(int n) {
    int preprev = 0;
    int prev = 1;
    int curri;
    for (int i = 2; i < n + 1; i++)
    {
        curri = preprev + prev;
        preprev = prev;
        prev = curri;
    }
    return prev;
}
    
int main() {
    int n = 5;
    // method-1
    // cout << fib(index);

    //method-2
    // vector<int> dp(n + 1, -1); // step 1
    // cout << fibm(n, dp);

    //method-3
    // vector<int> dp(n + 1);
    // cout << fibt(n, dp);

    //method-4
    // cout << fib(n);

    return 0;
}