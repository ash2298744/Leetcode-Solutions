class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        nums = []
        for i in range(len(arr)):
            for j in range(i + 1, len(arr)):
                nums.append([arr[i] / arr[j], arr[i], arr[j]])
        return sorted(nums, key= lambda x : x[0])[k - 1][1:]
