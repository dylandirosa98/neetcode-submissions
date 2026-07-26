class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        length = len(nums)
        i = 0
        while i < len(nums):
            if nums[i] == val:
                nums.pop(i)
                nums.append(None)
                length -= 1
            else:
                i += 1
        
        return length

