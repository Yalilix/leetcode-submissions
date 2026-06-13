class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        
        ret = ""
        for w in words:
            weight = 0
            for c in w:
                idx = ord(c) - ord('a')
                weight += weights[idx]

            weight = weight % 26

            ret += chr(ord('z') - weight)

        return ret

