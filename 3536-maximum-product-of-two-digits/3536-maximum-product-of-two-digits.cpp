class Solution {
public:
    int maxProduct(int n) {

        vector<int> vt;

        while (n > 0) {
            int digit = n % 10;
            vt.push_back(digit);
            n /= 10;
        }

        int lar = 0;
        int sl = 0;

        for (int i = 0; i < vt.size(); i++) {

            if (vt[i] > lar) {
                sl = lar;
                lar = vt[i];
            }
            else if (vt[i] > sl) {
                sl = vt[i];
            }
        }

        int ans = lar * sl;
        return ans;
    }
};