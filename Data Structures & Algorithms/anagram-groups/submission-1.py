class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        found_words = {}

        for word in strs:
            key = "".join(sorted(word))

            if key not in found_words:
                found_words[key] = []

            found_words[key].append(word)

        return list(found_words.values())