class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
                    int target =  0;


        for(int i=0;i<nums.size();i++){
            target = nums[i] * nums[i];

            ans.push_back(target);

        }

        sort(ans.begin() , ans.end());

        return ans;
        
    }
};