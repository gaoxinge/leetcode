class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp = [[0 for i in range(len(prices))] for k in range(3)]
        m = [[0 for i in range(len(prices))] for k in range(3)]
        for k in range(1, 3):
            for i in range(1, len(prices)):
                m[k][i] = min(m[k][i-1], prices[i-1] - dp[k-1][i-2]) if i > 1 else prices[0]
                dp[k][i] = max(dp[k][i-1], prices[i] - m[k][i])
        return dp[2][len(prices)-1]
