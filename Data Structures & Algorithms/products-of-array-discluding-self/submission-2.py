class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        answer = 1
        nonzeroanswer = None
        amount = 0
        for i in nums:
            if i == 0:
                nonzeroanswer = answer
                amount += 1
                continue
            else:
                answer *= i
        finallist = []
        for i in nums:
            if nonzeroanswer:
                if amount < 2 and i == 0:
                    finallist.append(answer)
                else:
                    finallist.append(0)
            else:
                finallist.append(answer//i)
        return finallist