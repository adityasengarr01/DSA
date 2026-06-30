class Solution {
public:
    char findTheDifference(string s, string t) {

        int freq[26] = {0};
        int frequ[26] = {0};

        for(int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        for(int j = 0; j < t.size(); j++) {
            frequ[t[j] - 'a']++;
        }

        for(int k = 0; k < 26; k++) {
            if(freq[k] != frequ[k]) {
                return 'a' + k;
            }
        }

        return '\0';
    }
};