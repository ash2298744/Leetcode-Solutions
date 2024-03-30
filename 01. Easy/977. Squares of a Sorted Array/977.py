# class Solution:
#     def sortedSquares(self, arr: List[int]) -> List[int]:
#         n = len(arr)
#         res = [0 for i in range(n)]
#         l, r, i = 0, n - 1, n - 1
#         while l <= r:
#             if arr[l] * arr[l] > arr[r] * arr[r]:
#                 res[i] = arr[l] * arr[l]
#                 l += 1
#             else:
#                 res[i] = arr[r] * arr[r]
#                 r -= 1
#             i -= 1
#         return res
    
# from sortedcontainers import SortedList
# s = SortedList()

# for i in range(10):
#     s.add(i)
# s.add(6)
            