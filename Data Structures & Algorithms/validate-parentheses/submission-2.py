class Solution:
    def isValid(self, s: str) -> bool:
        newlist = [] 
        for i in s:
            if i == "(" or i == "[" or i == "{":
                newlist.append(i)
            else:
                if len(newlist) == 0:
                    return False
                pop = newlist.pop()
                if i == ")":
                    if pop == "(":
                        continue
                    else:
                        return False
                if i == "]":
                    if pop == "[":
                        continue
                    else:
                        return False
                if i == "}":
                    if pop == "{":
                        continue
                    else:
                        return False
        if len(newlist) > 0:
            return False        
        return True