class Solution {
public:
    int n;
    int maxl;
    unordered_set<string> st;

    void solve(string& s, int i, string& current, int count) {
        if (count < 0)
            return;

        if (i == n) {

            if (count == 0) {

                if (current.length() > maxl) {
                    maxl = current.length();
                    st.clear();
                }

                if (current.length() == maxl) {
                    st.insert(current);
                }
            }

            return;
        }

        if (s[i] != '(' && s[i] != ')') {

            current.push_back(s[i]);

            solve(s, i + 1, current, count);

            current.pop_back();

            return;
        }

        current.push_back(s[i]);

        if (s[i] == '(')
            solve(s, i + 1, current, count + 1);
        else
            solve(s, i + 1, current, count - 1);

        current.pop_back();

        solve(s, i + 1, current, count);
    }

    vector<string> removeInvalidParentheses(string s) {

        n = s.length();
        maxl = 0;

        string current = "";

        solve(s, 0, current, 0);

        return vector<string>(st.begin(), st.end());
    }
};