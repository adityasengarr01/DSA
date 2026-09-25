class Solution {
public:

    bool solve(string &s, int i, stack<char>& sp) {

        if(i == s.length()) {
            return sp.empty();
        }

        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            sp.push(s[i]);

            return solve(s, i + 1, sp);
        }

        if(sp.empty()) {
            return false;
        }

        if((s[i] == ')' && sp.top() == '(') ||
           (s[i] == ']' && sp.top() == '[') ||
           (s[i] == '}' && sp.top() == '{')) {

            sp.pop();

            return solve(s, i + 1, sp);
        }

        return false;
    }

    bool isValid(string s) {
        stack<char> sp;

        return solve(s, 0, sp);
    }
};