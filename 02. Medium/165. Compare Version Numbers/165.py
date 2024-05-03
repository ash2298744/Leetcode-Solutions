class Solution:
    def separate(self, v, arr):
            curr = 0
            for i in v:
                if i != ".":
                    curr = curr * 10 + int(i)
                else:
                    arr.append(curr)
                    curr = 0
            arr.append(curr)

    def compareVersion(self, version1: str, version2: str) -> int:
        v1, v2 = [], []

        self.separate(version1, v1)
        self.separate(version2, v2)

        n1, n2 = len(v1), len(v2)
        
        if n1 > n2:
            v2 += [0] * (n1 - n2)
        elif n2 > n1:
            v1 += [0] * (n2 - n1)

        for i, j in zip(v1, v2):
            if i < j: return -1
            if i > j: return 1
        return 0
        