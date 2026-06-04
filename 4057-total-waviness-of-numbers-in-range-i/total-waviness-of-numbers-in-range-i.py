class Solution:
    LIMIT = 10**5 + 1
    dp = [0] * LIMIT
    prefixSum = [0] * LIMIT

    for i in range(100, LIMIT):
        r = i % 10
        m = (i // 10) % 10
        l = (i // 100) % 10

        isWave = m > max(l, r) or m < min(l, r)
        dp[i] = dp[i // 10] + int(isWave)
        prefixSum[i] = prefixSum[i - 1] + dp[i]

    def totalWaviness(self, num1: int, num2: int) -> int:
        return self.prefixSum[num2] - self.prefixSum[num1 - 1]
                

