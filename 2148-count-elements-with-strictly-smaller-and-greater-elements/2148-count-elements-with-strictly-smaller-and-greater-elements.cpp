class Solution {
public:
    int countElements(vector<int>& nums) {
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {

            bool smaller = false;
            bool greater = false;

            for(int j = 0; j < nums.size(); j++) {

                if(nums[j] < nums[i]) {
                    smaller = true;
                }

                if(nums[j] > nums[i]) {
                    greater = true;
                }
            }

            if(smaller && greater) {
                count++;
            }
        }

        return count;
    }
};