class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mapped = set()
        for i, j in zip(s, t):
            mapped.add((i, j))
        return len(mapped) == len(set(s)) and len(set(s)) == len(set(t))
