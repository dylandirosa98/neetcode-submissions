class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        found_words = {}
        final_list = []
        sorted_words = ["".join(sorted(word)) for word in strs]
        for i in range(len(strs)):
            new_word = "".join(sorted(strs[i]))
            if new_word in found_words:
                found_words[new_word].append(i)
            else:
                found_words[new_word] = [i]
            if new_word not in sorted_words[i+1:]:
                added_list = []
                for i in found_words[new_word]:
                    added_list.append(strs[i])
                final_list.append(added_list)
        return final_list