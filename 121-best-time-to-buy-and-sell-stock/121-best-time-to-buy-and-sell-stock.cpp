class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxP = 0, curr_mx = prices[n-1];
        
        for(int i = n-2; i >= 0; i--){
            curr_mx = max(curr_mx , prices[i]);
            maxP = max(maxP , curr_mx-prices[i]);
        }
        
        return maxP;
    }
};