class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        xor = 0
        for i in nums:
            xor ^= i
            
        bits1 = [0 for i in range(32)]
        bits2 = [0 for i in range(32)]
        
        a = bin(xor)[2:][::-1]
        for i in range(len(a)):
            if a[i] == '1':
                bits1[i] += 1
                
        b = bin(k)[2:][::-1]
        for i in range(len(b)):
            if b[i] == '1':
                bits2[i] += 1
                
        cnt = 0
        for i in range(32):
            if bits1[i] != bits2[i]:
                cnt += 1
        return cnt
        