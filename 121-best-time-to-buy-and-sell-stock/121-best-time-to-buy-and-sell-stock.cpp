class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxR(n);
        maxR[n-1] = prices[n-1];
        
        for(int i = n-2; i >= 0; i--){
            maxR[i] = max(maxR[i+1] , prices[i]);
        }
        
        int maxP = 0;
        
        for(int i = 0; i < n; i++){
            maxP = max(maxR[i]-prices[i] , maxP);    
        }
        
        return maxP;
    }
};