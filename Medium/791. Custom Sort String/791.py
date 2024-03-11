class Solution:
    def customSortString(self, order: str, s: str) -> str:
        for i in s:
            if i not in order:
                order += i

        res = ""
        for i in order:
            for j in s:
                if i == j:
                    res += j
        return res