class Solution {
public:
    int maxProduct(int n) {
        vector<int> vt;
        while(n>0){
        int digit = n%10;
        vt.push_back(digit);
        n /=10;
        }
        int maxi = 0;

        for(int i=0;i<vt.size();i++){
            for(int j=i+1;j<vt.size();j++){
                maxi = max(maxi,vt[i] * vt[j]);

                                
            }

        }
        return maxi;
        
    }
};