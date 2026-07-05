class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) > len(t):
            temp = t
            t = s
            s = temp
        matched_characters = list(t)
        for i in s:
            if i in matched_characters:
                matched_characters.remove(i)
        if len(matched_characters) == 0:
            return True
        return False