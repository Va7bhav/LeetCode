class Solution:
    def profitableSchemes(self, n: int, minProfit: int, group: List[int], profit: List[int]) -> int:
        dp = defaultdict(int)

        for m in range(n + 1):
            dp[(len(group), m, minProfit)] = 1

        for i in range(len(group) - 1, - 1, -1):
            for m in range(n + 1):
                for p in range(minProfit + 1):
                    not_take = dp[(i + 1, m, p)]

                    if m + group[i] <= n:
                        take = dp[(i + 1, m + group[i], p + profit[i])]

                    dp[(i + 1, m, p)] = take + not_take

        return max(dp.values())
        