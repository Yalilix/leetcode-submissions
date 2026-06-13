class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        
        ret = ""
        
        for w in words:
            weight = sum(weights[ord(c) - ord('a')] for c in w)
            ret += chr(ord('z') - (weight % 26))

        return ret

