class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";

        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {

                int left = i;
                int right = j;
                bool flag = true;

                while(left < right) {
                    if(s[left] != s[right]) {
                        flag = false;
                        break;
                    }
                    left++;
                    right--;
                }

                if(flag && j - i + 1 > ans.size()) {
                    ans = s.substr(i, j - i + 1);
                }
            }
        }

        return ans;
    }
};