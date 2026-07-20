class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }
        vector<pair<char, int>> v;
        for (auto it : freq) {
            v.push_back(it);
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });
        string ans = "";

        for (auto it : v) {
            for (int i = 0; i < it.second; i++) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};