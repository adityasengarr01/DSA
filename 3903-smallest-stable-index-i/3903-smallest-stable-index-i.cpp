class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sm(n);

        sm[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            sm[i] = min(nums[i], sm[i + 1]);
        }

        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);

            int mini = sm[i];

            if (maxi - mini <= k) {
                return i;
            }
        }

        return -1;
    }
};