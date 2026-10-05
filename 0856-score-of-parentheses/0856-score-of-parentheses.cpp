class Solution {
public:
    int scoreOfParentheses(string s) {
        int open = 0;
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                open++;
            } else {
                if (s[i - 1] == '(') {
                    ans += 1 << (open - 1);
                }

                open--;
            }
        }

        return ans;
    }
};