class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;
        for(int i=0;i<score.size();i++){
            int rank = 1;
            for(int j=0;j<score.size();j++){
                if(score[j] > score[i]){
                    rank++;
                }
            }
        
        if(rank == 1){
            ans.push_back("Gold Medal");
        }
        else if(rank == 2){
            ans.push_back("Silver Medal");
        }
        else if( rank == 3){
            ans.push_back("Bronze Medal");
        }
        else{
            ans.push_back(to_string(rank));

        }
        }
        return ans;
        
    }
};