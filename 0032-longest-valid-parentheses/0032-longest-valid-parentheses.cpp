class Solution {
public:
    int longestValidParentheses(string s) {

        int open = 0;
        int close = 0;
        int n = s.length();

        int result = 0;

        // LEFT TO RIGHT
        for (int i = 0; i < n; i++) {

            if (s[i] == '(')
                open++;
            else
                close++;

            if (open == close) {
                result = max(result, open + close);
            } else if (close > open) {
                open = 0;
                close = 0;
            }
        }

        open = 0;
        close = 0;

        // RIGHT TO LEFT
        for (int i = n - 1; i >= 0; i--) {

            if (s[i] == '(')
                open++;
            else
                close++;

            if (open == close) {
                result = max(result, open + close);
            } else if (open > close) {
                open = 0;
                close = 0;
            }
        }

        return result;
    }
};
/* in this taking the two variable which is name as open and close

open =0;
close =0;

and if open == close ---> store this in result;
here result = open +close;
and if close is > open  ----> this means that invalid parenthess so -------
                                                                           |
                                                                           |
                                                                       <<<<<
            then i updated the open and close ->> open == close == 0;


 and then  retrun max(result , open+close);
 ➡️for left to right check and if (open > close)
 ----------------------------------------------------------------------------------------------
➡️now for right to left traversal for parenthess like ->> "()(()"
so, traverse from right to left
if close > open more backward ;
condition is if (open > close) reset the value of open and close;
if(open == close) result open + close;
and return the result value;
*/
