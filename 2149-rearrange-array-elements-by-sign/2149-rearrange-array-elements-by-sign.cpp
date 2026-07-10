class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

            vector<int> pos;
            vector<int> neg;
        for(int i=0;i<nums.size();i++){
            if( nums[i] < 0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);

            }
            

        }
        vector<int> ans;

        for(int j = 0;j< pos.size();j++){
 
 ans.push_back(pos[j]);
 ans.push_back(neg[j]);
        }

        return ans;
        
    }
};