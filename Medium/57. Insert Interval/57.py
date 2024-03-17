class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        intervals.append(newInterval)
        intervals = sorted(intervals, key = lambda x : x[0])

        ans, prev = [], intervals.pop(0)
        while intervals:
            a, b = intervals[0][0], intervals[0][1]
            if a >= prev[0] and a <= prev[1]:
                prev[0] = min(prev[0], a)
                prev[1] = max(b, prev[1])
                intervals.pop(0)
            else:
                ans.append(prev)
                prev = intervals.pop(0)
        return ans + [prev]
        