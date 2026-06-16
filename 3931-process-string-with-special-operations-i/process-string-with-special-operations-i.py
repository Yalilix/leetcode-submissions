class Solution:
    def processStr(self, s: str) -> str:
        result = ""
        hm = {"*": 1, "#": 1, "%": 1}
        for c in s:
            if c in hm:
                if c == '*':
                    result = result[:-1]
                elif c == '#':
                    result += result
                else:
                    result = result[::-1]

            else:
                result += c

        return result                    
            
