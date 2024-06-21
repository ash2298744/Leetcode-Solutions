class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        n = len(customers)

        tot = 0
        for i in range(n):
            if grumpy[i] == 0:
                tot += customers[i]

        ans = j = 0
        for i in range(n):
            if grumpy[i] == 1:
                tot += customers[i]
            
            if (i - j + 1) > minutes:
                if grumpy[j] == 1:
                    tot -= customers[j]
                j += 1
            
            ans = max(ans, tot)
        return ans
        