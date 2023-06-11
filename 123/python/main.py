class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp = [[0 for i in range(len(prices))] for k in range(3)]
        for k in range(1, 3):
            for i in range(1, len(prices)):
                m = prices[0]
                for j in range(1, i):
                    m = min(m, prices[j] - dp[k-1][j-1])
                dp[k][i] = max(dp[k][i-1], prices[i] - m)
        return dp[2][len(prices)-1]

