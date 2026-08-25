class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = {}
        for i in strs:
            x = ''.join(sorted(i))
            if x in hashmap:
                hashmap[x].append(i)
                continue
            hashmap[x] = [i]
        return list(hashmap.values())