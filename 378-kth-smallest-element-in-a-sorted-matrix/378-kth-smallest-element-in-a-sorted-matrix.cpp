#define pi pair<pair<int,int>,int>
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        
        for(int i = 0; i < matrix.size(); i++){
            pq.push({{matrix[i][0] , i},0});
        }
        
        vector<int> v;
        
        while(!pq.empty()){
            auto t = pq.top().first;
            int indx = t.second;
            int val = t.first;
            int num = pq.top().second;
            
            v.push_back(val);
            
            if(num+1 < matrix.size()){
                pq.push({{matrix[indx][num+1] , indx} , num+1});
            }
            
            if(v.size() == k)return v[k-1];
            pq.pop();
        }
        
        return -1;
    }
};