class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.size() != goal.size())
            return false;

        if (s == goal)
            return true;

        int n = goal.size();

        for (int i = 0; i < n; i++) {

            char temp = goal[0];

            
            for (int j = 0; j < n - 1; j++) {
                goal[j] = goal[j + 1];
            }

            goal[n - 1] = temp;

            if (goal == s)
                return true;
        }

        return false;
    }
};