class Solution:
    def calPoints(self, operations: List[str]) -> int:
        score = []
        for i in range(len(operations)):
            if operations[i] == "C":
                score.pop()
            elif operations[i] == "+":
                new = score[len(score)-1] + score[len(score)-2]
                score.append(new)
            elif operations[i] == "D":
                score.append(score[len(score)-1] * 2)
            else:
                score.append(int(operations[i]))
        return sum(score)