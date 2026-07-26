class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int lar = INT_MIN;
        int sec = INT_MIN;
        int thi = INT_MIN;

        int small1 = INT_MAX;
        int small2 = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] > lar) {
                thi = sec;
                sec = lar;
                lar = nums[i];
            }
            else if (nums[i] > sec) {
                thi = sec;
                sec = nums[i];
            }
            else if (nums[i] > thi) {
                thi = nums[i];
            }

            if (nums[i] < small1) {
                small2 = small1;
                small1 = nums[i];
            }
            else if (nums[i] < small2) {
                small2 = nums[i];
            }
        }

        return max(lar * sec * thi, lar * small1 * small2);
    }
};