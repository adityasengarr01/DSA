class Solution {
public:
    int reverseDegree(string s) {
        int n = 0;
        for(int i=0;i<s.length();i++){
            int t = 26 - (s[i] - 'a');
            n += t * (i+1);

        }
        return n;
        
    }
};