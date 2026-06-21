class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        ret = 0

        for c in costs:
            if coins < c: break
            ret += 1
            coins -= c

        return ret