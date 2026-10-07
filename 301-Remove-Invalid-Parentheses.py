class Solution:
    def removeInvalidParentheses(self, s):
        def valid(x):
            count = 0

            for ch in x:
                if ch == '(':
                    count += 1
                elif ch == ')':
                    count -= 1

                if count < 0:
                    return False

            return count == 0

        level = {s}

        while True:
            answer = []

            for x in level:
                if valid(x):
                    answer.append(x)

            if answer:
                return answer

            next_level = set()

            for x in level:
                for i in range(len(x)):
                    if x[i] in "()":
                        next_level.add(x[:i] + x[i+1:])

            level = next_level