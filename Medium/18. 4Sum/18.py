class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        ans = []

        i = 0
        while i < n - 3:
            j = i + 1

            while j < n - 2:
                ii = j + 1
                jj = n - 1
                val = nums[i] + nums[j]

                while ii < jj:
                    if (val + nums[ii] + nums[jj]) == target:
                        ans.append([nums[i], nums[j], nums[ii], nums[jj]])

                        temp = nums[ii]
                        while ii < jj and nums[ii] == temp:
                            ii += 1

                        temp = nums[jj]
                        while ii < jj and nums[jj] == temp:
                            jj -= 1

                    elif (val + nums[ii] + nums[jj]) < target:
                        ii += 1
                    else:
                        jj -= 1

                temp = nums[j]
                while j < n - 2 and nums[j] == temp:
                    j += 1

            temp = nums[i]
            while i < n - 3 and nums[i] == temp:
                i += 1

        return ans
