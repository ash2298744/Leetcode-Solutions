class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int> q;
        for(int i = 0; i < students.size(); i++) {
            q.push_back(students[i]);
        }

        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                int curr_student = q.front();
                q.pop_front();
                if(curr_student == sandwiches[0]) {
                    sandwiches.erase(sandwiches.begin());
                    break;
                }
                q.push_back(curr_student);
            }
            if(n == q.size()) break;
        }
        return q.size();
    }
};
