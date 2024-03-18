class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points = sorted(points, key = lambda x : x[1])
        cnt, prev = 1, points[0][1]
        for i in range(1, len(points)):
            if prev < points[i][0] or prev > points[i][1]:
                cnt += 1
                prev = points[i][1]
        return cnt
