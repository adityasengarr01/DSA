class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool s[26] = {false};

        for(int i=0;i<sentence.length();i++){
            s[sentence[i] - 'a'] = true;

        }

        for(int i=0;i<26;i++){
            if(s[i] == false){
                return false;
            }
        }
        return true;
        
    }
};