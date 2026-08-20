# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def mergeSort(self, pairs: List[Pair]) -> List[Pair]:
        s = 0
        e = len(pairs) - 1
        return self.theMergeSort(pairs, s, e)


    def theMergeSort(self, pairs, s, e):
        if e-s + 1 <= 1:
            return pairs
        m = (s + e) // 2
        self.theMergeSort(pairs, s, m)
        self.theMergeSort(pairs, m+1, e)

        self.merge(pairs, s, e, m)
        return pairs

        
    def merge(self, pairs, s, e, m):
        L = pairs[s:m+1]
        R = pairs[m + 1: e + 1]

        i = 0 
        j = 0 
        r = s

        while i < len(L) and j < len(R):
            if L[i].key <= R[j].key:
                pairs[r] = L[i]
                i += 1
            else:
                pairs[r] = R[j]
                j += 1
            r += 1
        while i < len(L):
            pairs[r] = L[i]
            i += 1
            r += 1
        while j < len(R):
            pairs[r] = R[j]
            j += 1
            r += 1

    