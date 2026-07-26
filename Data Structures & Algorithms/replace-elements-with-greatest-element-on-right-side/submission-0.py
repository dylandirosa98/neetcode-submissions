class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        themax = max(arr)
        maxes = []
        for i in range(len(arr)-1):
            if arr[i] == themax:
                themax = max(arr[i+1:])

            maxes.append(themax)
        maxes.append(-1)
        return maxes