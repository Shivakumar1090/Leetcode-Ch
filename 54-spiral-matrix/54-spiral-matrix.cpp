class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        int row_start = 0 , col_start = 0 , row_end = n-1 , col_end = m-1;
        vector<int> v;
        
        while(row_start <= row_end || col_start <= col_end){
            //row start
            for(int i = col_start; i <= col_end; i++){
                if(col_start > col_end || row_start > row_end)break;
                v.push_back(matrix[row_start][i]);
            }
            row_start++;
            
            //col end
            for(int i = row_start; i <= row_end; i++){
                if(col_start > col_end || row_start > row_end)break;
                v.push_back(matrix[i][col_end]);
            }
            col_end--;
            
            //row_end
            for(int i = col_end; i >= col_start; i--){
                if(col_start > col_end || row_start > row_end)break;
                v.push_back(matrix[row_end][i]);
            }
            row_end--;
            
            //col Start
            for(int i = row_end; i >= row_start; i--){
                if(col_start > col_end || row_start > row_end)break;
                v.push_back(matrix[i][col_start]);
            }
            col_start++;
        }
        
        return v;
    }
};