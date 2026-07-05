class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        new_list = nums.copy()
        for i in nums:
            new_list.append(i)
        return new_list
        