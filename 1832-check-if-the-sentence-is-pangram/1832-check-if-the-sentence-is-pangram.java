class Solution {
    public boolean checkIfPangram(String sentence) {
        boolean[] s = new boolean[26];

        for(int i=0;i<sentence.length();i++){
            s[sentence.charAt(i) - 'a'] = true;
        }
        for(int j=0;j<26;j++){
            if(s[j] == false){
                return false;
            }
        }

        return true;
        
    }
}