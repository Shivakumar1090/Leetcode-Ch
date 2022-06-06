class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int left = 0 , right = n-1 , area = 0;
        
        while(left <= right){
            int width = right-left;
            int height = min(arr[left] , arr[right]);
            area = max(area,width*height);
            
            if(arr[left] > arr[right])right--;
            else if(arr[right] > arr[left])left++;
            else right-- , left++;
        }
        
        return area;
    }
};