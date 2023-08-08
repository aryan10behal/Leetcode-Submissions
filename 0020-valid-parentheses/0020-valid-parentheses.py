class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        for x in s:
            if x == '(' or x == '[' or x == '{':
                st.append(x)
            else:
                if len(st) == 0:
                    return False
                elif x == ')':
                    if st[len(st)-1] == '(':
                        st.pop()
                    else:
                        return False
                elif x == ']':
                    if st[len(st)-1] == '[':
                        st.pop()
                    else:
                        return False
                elif x == '}':
                    if st[len(st)-1] == '{':
                        st.pop()
                    else:
                        return False
        return True if len(st) == 0 else False
                
                