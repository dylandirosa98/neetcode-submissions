class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        zero = 0
        one = 0 
        for i in students:
            if i == 0:
                zero += 1
            else:
                one += 1
        sandwichcount = 0
        while True:
            if sandwiches[sandwichcount] == 0:
                if zero > 0:
                    zero -= 1
                else:
                    return one
            else:
                if one > 0:
                    one -= 1
                else:
                    return zero
            if one + zero == 0:
                return 0
            sandwichcount += 1