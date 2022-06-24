class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // cost[1] = min(cost[1],cost[0]);
        for(int i = 2; i < n; i++){
            cost[i] += min(cost[i-1],cost[i-2]); 
        }
        // cost[n-1] = min(cost[n-1]+cost[n-2] , cost[n-2]);
        return min(cost[n-1],cost[n-2]);
    }
};