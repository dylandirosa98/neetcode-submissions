class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        found_words = {}

        for i in range(len(strs)):
            key = "".join(sorted(strs[i]))
            if key not in found_words:
                found_words[key] = []
            found_words[key].append(strs[i])

        return list(found_words.values())
        
