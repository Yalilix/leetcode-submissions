class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        hm = {
            "b": 1,
            "a": 1,
            "l": 2,
            "o": 2,
            "n": 1,
            }

        count = {}
        
        for c in text:
            count[c] = 1 + count.get(c, 0)

        ret = inf
        unique = set()

        double = {
            "l": 0,
            "o": 0
        }

        for k, v in count.items():
            if k not in hm: continue
            cur = v // hm[k]
            ret = min(ret, cur)
            unique.add(k)



        return ret if len(unique) == 5 else 0