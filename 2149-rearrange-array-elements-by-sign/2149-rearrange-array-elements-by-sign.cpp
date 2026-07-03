class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       vector<int> m;
       vector<int> t;

       for(int i=0;i<nums.size();i++){

        if(nums[i] >=0 ){
            m.push_back(nums[i]);
        }
        else{
            t.push_back(nums[i]);
        }
       }
       vector<int> z;
      

        int p=0;
        int q = 0;
        for(int j=0;j<m.size();j++){

            z.push_back(m[p]);
            p++;

            z.push_back(t[q]);
            q++;
        }
       return z;

        

       
        
    }
};