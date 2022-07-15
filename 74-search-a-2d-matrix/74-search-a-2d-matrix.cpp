class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n = arr.size();
        int m = arr[0].size() , row = -1;
        
        for(int i = 0; i < n; i++){
            if(arr[i][m-1] == target)return true;
            if(arr[i][m-1] > target){
                row = i;
                break;
            }
        }
        
        if(row == -1)return false;
        
        int start = 0, end = m;
        while(start <= end){
            int mid = start+(end-start)/2;
            if(arr[row][mid] == target)return true;
            if(arr[row][mid] < target){
                start = mid+1;
            }
            else end = mid-1;
        }
        
        return false;
    }
};