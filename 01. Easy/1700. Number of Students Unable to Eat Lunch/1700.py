class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        q = deque(students)
        while q:
            n = len(q)
            for _ in range(n):
                curr_student = q.popleft()
                if curr_student == sandwiches[0]:
                    sandwiches.pop(0)
                    break
                q.append(curr_student)
            if n == len(q):
                break
        return len(q)
