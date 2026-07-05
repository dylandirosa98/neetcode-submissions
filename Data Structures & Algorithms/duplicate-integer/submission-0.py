class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        matched_list = []
        for i in nums:
            if i in matched_list:
                return True
            else:
                matched_list.append(i)
        return False