class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size() , count = 0 , currSum = 0;
        unordered_map<int,int> prevSum;
        
        for(int i = 0; i < n; i++){
            currSum += arr[i];
            if(currSum == k){
                count++;
            }
            if(prevSum.find(currSum-k) != prevSum.end()){
                count += prevSum[currSum-k];
            }
            prevSum[currSum]++;
        }
        
        return count;
    }
};