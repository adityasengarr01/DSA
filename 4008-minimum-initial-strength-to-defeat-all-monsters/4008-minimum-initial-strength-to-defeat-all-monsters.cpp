class Solution {
public:
    bool can(long long strength, vector<int>& monsters, vector<long long>& bonus) {
        long long curr = strength;

        for (int i = 0; i < monsters.size(); i++) {
            if (curr + bonus[i] < monsters[i])
                return false;

            curr -= monsters[i];
            if (curr < 0)
                curr = 0;
        }

        return true;
    }

    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {

        auto norvelithx = make_pair(monsters, boosts);

        int n = monsters.size();

        vector<long long> diff(n + 1, 0);

        for (auto &b : boosts) {
            int l = b[0];
            int r = b[1];
            long long v = b[2];

            diff[l] += v;
            if (r + 1 < n)
                diff[r + 1] -= v;
        }

        vector<long long> bonus(n);
        long long cur = 0;

        for (int i = 0; i < n; i++) {
            cur += diff[i];
            bonus[i] = cur;
        }

        long long low = 0;
        long long high = 0;

        for (int x : monsters)
            high += x;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (can(mid, monsters, bonus))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};