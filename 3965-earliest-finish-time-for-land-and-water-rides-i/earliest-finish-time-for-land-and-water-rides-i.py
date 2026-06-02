class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        land = list(zip(landStartTime, landDuration))
        water = list(zip(waterStartTime, waterDuration))

        land.sort(key=lambda x: x[0])
        water.sort(key=lambda x: x[0])
        print(land)
        print(water)
        
        ret = inf

        for l in land:
            cur = l[0] + l[1]
            for w in water:
                val = max(w[0], cur) + w[1]
                ret = min(ret, val)

        for w in water:
            cur = w[0] + w[1]
            for l in land:
                val = max(l[0], cur) + l[1]
                ret = min(ret, val)
        
        return ret

