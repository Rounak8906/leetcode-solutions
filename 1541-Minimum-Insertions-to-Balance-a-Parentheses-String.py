
class Solution(object):
    def minInsertions(self, s):
        insertions = 0
        open_brackets = 0
        i = 0

        while i < len(s):
            if s[i] == '(':
                open_brackets += 1

            else:
                # If the next character is also ')',
                # we have a pair of closing brackets.
                if i + 1 < len(s) and s[i + 1] == ')':
                    i += 1
                else:
                    # Insert one ')' to complete the pair.
                    insertions += 1

                if open_brackets > 0:
                    open_brackets -= 1
                else:
                    # Insert an opening '('.
                    insertions += 1

            i += 1

        # Each remaining '(' needs two ')'.
        insertions += open_brackets * 2

        return insertions
