class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
        int n = v.size();
        
        for(int i = n-1; i > 0; i--){
            for(int j = 0; j < v[i].size()-1; j++){
                v[i-1][j] += min(v[i][j] , v[i][j+1]);
            }
        }
        
        return v[0][0];
    }
};