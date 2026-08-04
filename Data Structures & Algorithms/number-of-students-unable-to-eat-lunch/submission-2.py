class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        studentcount = 0
        sandwichcount = 0
        count = 0
        length = len(students)
        while count < len(sandwiches):
            if students[studentcount%len(students)] == sandwiches[sandwichcount]:
                sandwichcount += 1
                count = 0
                del students[studentcount%len(students)]
            studentcount += 1
            count += 1
            if sandwichcount == len(sandwiches):
                return 0
        return len(sandwiches) - sandwichcount
        