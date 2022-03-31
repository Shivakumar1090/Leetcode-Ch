class Solution {
public:
    int splitArray(vector<int>& arr, int M) {
        int n = arr.size();
        int low = INT_MIN , high = 0 , res =-1;
        for(int i = 0; i < n; i++)
        {
            high += arr[i];
            low = max(low,arr[i]);
        }
        
        while(low <= high)
        {
            int mid  = low + (high-low)/2;
            int sum = 0 , count = 1;
            for(int i = 0; i < n; i++)
            {
                sum += arr[i];
                if(sum > mid){
                    sum = arr[i];
                    count++;
                }
            }
            
            if(count > M)
                low = mid+1;
            else 
            {
                res = mid;
                high = mid-1;
            }
        }
        return res;
    }
};