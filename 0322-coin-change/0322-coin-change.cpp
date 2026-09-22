class Solution {
public:
    vector<int> coins;
    int n;
    vector<vector<int>> dp;

    int solve(int idx, int amt) {
        if(amt == 0)
            return 0;

        if(amt < 0 || idx >= n)
            return 1e9;

        if(dp[idx][amt] != -1)
            return dp[idx][amt];

        // Take
        int take = 1 + solve(idx, amt - coins[idx]);

        // Skip
        int skip = solve(idx + 1, amt);

        return dp[idx][amt] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        this->coins = coins;
        this->n = coins.size();

        dp.assign(n, vector<int>(amount + 1, -1));

        int ans = solve(0, amount);

        return ans == 1e9 ? -1 : ans;
    }
};

// [1 , 2 , 5];

// amount = 5

// a) [1 , 1 ,1 , 1 , 1] cnt = 5

// d) [1 , 1 , 1 , 2]  cnt = 4

// b) [1 , 2 , 2] cnt = 3

// ----------------
// c) [5] cnt = 1 |
// ----------------

// 4 valid options ans ane kai => hume is question mai yeh batana ki ktine
// tareko sai tu amount bana parah=>

// ------------------------------------------------------------------------------