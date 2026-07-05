class Solution:

    def encode(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        encoded_string = ":;".join(strs) + ":;"
        return encoded_string
    def decode(self, s: str) -> List[str]:
        if len(s) == 0:
            return []
        the_list = []
        j = 0
        for i in range(len(s)-1):
            if s[i] + s[i+1] == ":;":
                the_list.append(s[j:i])
                j += i - j + 2
        return the_list
