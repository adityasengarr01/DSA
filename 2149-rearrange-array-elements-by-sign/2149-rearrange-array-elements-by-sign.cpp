class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> nunu(nums.size());

        int p = 0;
        int n = 1;

        for(int i=0;i<nums.size();i++){
            if(nums[i] >=0){
                nunu[p] = nums[i];
                p +=2;

            }
            else{
            nunu[n] = nums[i];
            n +=2;
            }

        }
        return nunu;


        
    }
};