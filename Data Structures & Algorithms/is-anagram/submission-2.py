class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(t) != len(s):
            return False
        countT, countS = {}, {}
        for i in range(len(t)):
            countT[t[i]] = 1 + countT.get(t[i], 0)
            countS[s[i]] = 1 + countS.get(s[i], 0)
        for c in countT:
            if countT[c] != countS.get(c, 0):
                return False
        return True
        