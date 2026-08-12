class Solution {
public:
    int nextGreaterElement(int n) {
     string s = to_string(n);
             int pivot = -1;


     for(int i = s.size()-2;i>=0;i--){
        if(s[i] < s[i+1]){
            pivot  = i;

            for(int j=s.size()-1;j>pivot;j--){

                if(s[pivot] < s[j]){
                    swap(s[pivot] , s[j]);
                    break;
                }
            }
                            reverse(s.begin() + pivot + 1, s.end());
                            break;



        }
     }
     if(pivot == -1){
        return -1;
     }

        long long ans = stoll(s);

        if(ans > INT_MAX) {
            return -1;
        }

        return ans;
        
    }
};