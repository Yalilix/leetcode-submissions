class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort(key= lambda x:-x)

        ret = 0
        for i in range(len(cost)):
            if i % 3 != 2:
                ret += cost[i]
        return ret