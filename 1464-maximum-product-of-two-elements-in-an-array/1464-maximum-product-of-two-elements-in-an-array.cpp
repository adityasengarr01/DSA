class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int lar = 0;
        int sec = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > lar){
                sec = lar;
                lar = nums[i];

            }
             else if(nums[i] > sec){
                sec = nums[i];
            }

        }
        int ans = (lar-1) * (sec -1);

        return ans;
        
    }
};