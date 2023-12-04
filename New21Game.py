class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        # dp = {}
        # def dfs(score):
        #     if score >= k:
        #         return 1 if score <= n else 0
                
        #     if score in dp: return dp[score]
        #     prob = 0
        #     for i in range(1, maxPts + 1):
        #         prob += dfs(score + i)

        #     dp[score] = prob / maxPts
        #     return prob / maxPts
        

        class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        if k == 0:
            return 1.0

        windowSum = 0

        for i in range(k, k + maxPts):
            windowSum += 1 if i <= n else 0

        dp = {}
        for i in range(k - 1, -1, -1):
            tot = 0
            for j in range(i, i + maxPts):
                dp[i] = 
        dp = defaultdict()
        for s in range(score + 1):
            if s >= k and s <= n:
                dp[s] = 1
        for s in range(score, -1, -1):

        dfs(0)