class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        n = len(arr)
        xorCount = 0
        for i in range(n - 1):
            xor = 0
            for j in range(i, n):
                xor ^= arr[j]
                if xor == 0:
                    xorCount += (j - i)
        return xorCount
        