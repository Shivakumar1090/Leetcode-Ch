class Solution {
public:
    vector<int> getRow(int rowIndx) {
        vector<int> ans(rowIndx+1,0);
        ans[0] = 1;
        
        for(int i = 1; i <= rowIndx; i++){
            // ans[i] = ans[i-1]*(rowIndx-i+1)/i;
            for(int j = i; j >= 1; j--)
                ans[j] += ans[j-1];
        }
        
        return ans;
    }
};