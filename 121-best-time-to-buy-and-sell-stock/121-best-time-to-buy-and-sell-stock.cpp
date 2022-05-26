class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxP = 0, curr_mx = prices[n-1];
        
        for(int i = n-2; i >= 0; i--){
            curr_mx = max(curr_mx , prices[i]);
            maxP = max(maxP , curr_mx-prices[i]);
        }
        
//         for(int i = n-2; i >= 0; i--){
//             maxR[i] = max(maxR[i+1] , prices[i]);
//         }
        
//         int maxP = 0;
        
//         for(int i = 0; i < n; i++){
//             maxP = max(maxR[i]-prices[i] , maxP);    
//         }
        
        return maxP;
    }
};