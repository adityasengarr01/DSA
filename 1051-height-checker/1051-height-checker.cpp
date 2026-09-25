class Solution {
public:
    int heightChecker(vector<int>& heights) {

        vector<int> h;
        int count =0;

        for(int i=0;i<heights.size();i++){
            h.push_back(heights[i]);
        }
        sort(h.begin(), h.end());

        for(int j=0;j<heights.size();j++){
            if(heights[j] != h[j]){
                count++;
            }
        }
        return count;
        
    }
};