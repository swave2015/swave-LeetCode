class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            if c == '(' or  c == '[' or c == '{':
                stack.append(c)
            else:
                if not len(stack):
                    return False
                top = stack.pop()
                if c == ')':
                    match = '('
                elif c == ']':
                    match = '['
                else:
                    assert(c == '}')
                    match = '{'
                    
                if match != top:
                    return False
        if not len(stack):
            return True
        else:
            return False