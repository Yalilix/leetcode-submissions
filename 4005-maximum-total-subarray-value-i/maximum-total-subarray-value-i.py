class Solution:
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        curMax = max(nums)
        curMin = min(nums)

        return (curMax - curMin) * k

