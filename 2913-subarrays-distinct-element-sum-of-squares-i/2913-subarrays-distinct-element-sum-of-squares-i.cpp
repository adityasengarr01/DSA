class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                vector<int> sub;

                for (int k = i; k <= j; k++) {
                    sub.push_back(nums[k]);
                }

                set<int> st(sub.begin(), sub.end());

                int uniqueCount = st.size();

                ans += uniqueCount * uniqueCount;
            }
        }

        return ans;
    }
};