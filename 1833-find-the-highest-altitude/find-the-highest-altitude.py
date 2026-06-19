class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        alt = 0
        ret = 0
        for i in range(1, len(gain) + 1):
            alt += gain[i - 1]
            ret = max(ret, alt)

        return ret