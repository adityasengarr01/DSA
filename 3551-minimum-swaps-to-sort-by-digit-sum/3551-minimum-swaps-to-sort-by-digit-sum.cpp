class Solution {
public:
    int digitSum(int n) {
        int sum = 0;

        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    void merge(vector<pair<pair<int, int>, int>>& arr,
               int low, int mid, int high) {
        vector<pair<pair<int, int>, int>> temp;

        int i = low;
        int j = mid + 1;

        while (i <= mid && j <= high) {
            if (arr[i].first <= arr[j].first) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }

        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= high) temp.push_back(arr[j++]);

        for (int k = low; k <= high; k++) {
            arr[k] = temp[k - low];
        }
    }

    void mergeSort(vector<pair<pair<int, int>, int>>& arr,
                   int low, int high) {
        if (low >= high) return;

        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<pair<int, int>, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({{digitSum(nums[i]), nums[i]}, i});
        }

        mergeSort(arr, 0, n - 1);

        vector<int> visited(n, 0);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i].second == i)
                continue;

            int cycle = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = 1;
                j = arr[j].second;
                cycle++;
            }

            if (cycle > 1)
                swaps += cycle - 1;
        }

        return swaps;
    }
};