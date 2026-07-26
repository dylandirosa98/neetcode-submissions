class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        themax = 0
        counter = 0
        for i in nums:
            if i == 1:
                counter += 1
            else:
                if counter > themax:
                    themax = counter
                counter = 0 
        themax = max(themax, counter)
        return themax
