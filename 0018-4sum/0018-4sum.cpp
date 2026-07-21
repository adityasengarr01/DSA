class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                unordered_set<long long> hashset;

                for (int k = j + 1; k < n; k++) {

                    long long sum = 0;
                    sum += nums[i];
                    sum += nums[j];
                    sum += nums[k];

                    long long fourth = (long long)target - sum;

                    if (hashset.find(fourth) != hashset.end()) {

                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }

                    hashset.insert(nums[k]);
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }
};