class Solution {
public:
    int countSquares(vector<vector<int>>& arr) {
        int rows = arr.size() , cols = arr[0].size();
        int k = max(rows,cols)+1;
        vector<int> sum(k,0);
        int res = 0;
        
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(arr[i][j] == 1){
                    arr[i][j] = min(min(arr[i][j-1] , arr[i-1][j]) , arr[i-1][j-1])+1;
                }
            }
        }
        
        for(int i = 0; i < rows;  i++){
            for(int j = 0; j < cols; j++){
                res += arr[i][j];
            }
        }
        return res;
    }
};