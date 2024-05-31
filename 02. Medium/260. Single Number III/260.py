class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xor = 0
        for i in nums:
            xor ^= i
            
        bit = xor & -xor
        ele1 = ele2 = 0
        for i in nums:
            if (i & bit):
                ele1 ^= i
            else:
                ele2 ^= i
        return [ele1, ele2]
                