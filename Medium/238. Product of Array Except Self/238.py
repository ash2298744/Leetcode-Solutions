class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [1]
        for i in range(n - 1, -1, -1):
            ans.append(ans[-1] * nums[i])
        ans.pop(0)
        ans = ans[::-1]

        pre = 1
        for i in range(n):
            if i == 0:
                ans[i] = ans[i + 1]
            elif i == n - 1:
                ans[i] = pre
            else:
                ans[i] = pre * ans[i + 1]
            pre *= nums[i]
        return ans
        