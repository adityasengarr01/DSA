class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){

            for(int j=0;j<s.size();j++){

                if(s[i] == s[j] && t[i]!=t[j]){
                    return false;
                }
                if(t[i] == t[j] && s[i] != s[j]){
                    return false;
                }

            }
        }
        return true;
        
    }
};