#include <bits/stdc++.h>
using namespace std;

int earliestFinishTime(vector<int>& landStartTime,
                       vector<int>& landDuration,
                       vector<int>& waterStartTime,
                       vector<int>& waterDuration) {

    int n = landStartTime.size();
    int m = waterStartTime.size();

    long long ans = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // Land -> Water
            long long landFinish =
                landStartTime[i] + landDuration[i];

            long long finish1 =
                max(landFinish,
                    (long long)waterStartTime[j])
                + waterDuration[j];

            // Water -> Land
            long long waterFinish =
                waterStartTime[j] + waterDuration[j];

            long long finish2 =
                max(waterFinish,
                    (long long)landStartTime[i])
                + landDuration[i];

            ans = min(ans, min(finish1, finish2));
        }
    }

    return (int)ans;
}

int main() {

    int n;
    cout << "Enter number of land rides: ";
    cin >> n;

    vector<int> landStartTime(n);
    vector<int> landDuration(n);

    cout << "Enter land start times: ";
    for (int i = 0; i < n; i++) {
        cin >> landStartTime[i];
    }

    cout << "Enter land durations: ";
    for (int i = 0; i < n; i++) {
        cin >> landDuration[i];
    }

    int m;
    cout << "Enter number of water rides: ";
    cin >> m;

    vector<int> waterStartTime(m);
    vector<int> waterDuration(m);

    cout << "Enter water start times: ";
    for (int i = 0; i < m; i++) {
        cin >> waterStartTime[i];
    }

    cout << "Enter water durations: ";
    for (int i = 0; i < m; i++) {
        cin >> waterDuration[i];
    }

    int answer = earliestFinishTime(
        landStartTime,
        landDuration,
        waterStartTime,
        waterDuration
    );

    cout << "Earliest Finish Time = " << answer << endl;

    return 0;
}