class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedVec;
        
        if(intervals.size() == 0)return mergedVec;
        
        sort(intervals.begin(),intervals.end());
        vector<int> tmpInterval = intervals[0];
        
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] <= tmpInterval[1]){
                tmpInterval[1] = max(intervals[i][1] , tmpInterval[1]);
            }
            else{
                mergedVec.push_back(tmpInterval);
                tmpInterval = intervals[i];
            }
        }
        
        mergedVec.push_back(tmpInterval);
        return mergedVec;
    }
};