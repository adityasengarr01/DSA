#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int calc(vector<int>& start1, vector<int>& dur1,
             vector<int>& start2, vector<int>& dur2) {

        int minEnd = INT_MAX;

        // Earliest finishing ride from first category
        for (int i = 0; i < start1.size(); i++) {
            minEnd = min(minEnd, start1[i] + dur1[i]);
        }

        int ans = INT_MAX;

        // Try every ride from second category
        for (int i = 0; i < start2.size(); i++) {
            int finishTime = max(minEnd, start2[i]) + dur2[i];
            ans = min(ans, finishTime);
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        // Land -> Water
        int landThenWater = calc(
            landStartTime,
            landDuration,
            waterStartTime,
            waterDuration
        );

        // Water -> Land
        int waterThenLand = calc(
            waterStartTime,
            waterDuration,
            landStartTime,
            landDuration
        );

        return min(landThenWater, waterThenLand);
    }
};

int main() {
    Solution obj;

    vector<int> landStartTime = {2, 8};
    vector<int> landDuration = {4, 1};

    vector<int> waterStartTime = {6};
    vector<int> waterDuration = {3};

    cout << obj.earliestFinishTime(
                landStartTime,
                landDuration,
                waterStartTime,
                waterDuration
            ) << endl;

    return 0;
}