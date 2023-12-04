
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<int> dp(amount + 1, 0), curr(amount + 1, 0);

        dp[0] = 1;
        for (int i = 0; i <= amount; i++)
            if (i % coins[0] == 0)
                dp[i] = 1;

        for (int ind = 1; ind < n; ind++)
        {
            for (int tar = 0; tar <= amount; tar++)
            {
                int take = 0, dtake = 0;
                dtake = dp[tar];
                if (coins[ind] <= tar)
                    take = curr[tar - coins[ind]];
                curr[tar] = take + dtake;
            }
            dp = curr;
        }

        return dp[amount];
    }
};
int main()
{

    return 0;
}