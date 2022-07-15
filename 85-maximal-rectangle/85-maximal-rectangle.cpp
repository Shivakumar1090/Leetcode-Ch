class Solution {
public:
    int LargeArea(vector<int> height){
        int n = height.size() , maxAnswer = 0;
        vector<int> left(n) , right(n);
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            while(!st.empty()){
                if(height[st.top()] >= height[i]){
                    st.pop();
                }
                else{
                  left[i] = st.top()+1;
                    break;
                } 
            }
            if(st.empty())left[i] = 0;
            st.push(i);
        }
        
        while(!st.empty())st.pop();
        
        for(int i = n-1; i >= 0; i--){
            while(!st.empty()){
                if(height[st.top()] >= height[i]){
                    st.pop();
                }
                else{
                  right[i] = st.top()-1;
                    break;
                } 
            }
            if(st.empty())right[i] = n-1;
            st.push(i);
            
            maxAnswer = max(maxAnswer , (right[i]-left[i]+1)*height[i]);
        }
        
        return maxAnswer;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<int> histogram(m);
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '0'){
                    histogram[j] = 0;
                }
                else{
                    histogram[j] += 1;
                }
            }
            ans = max(ans,LargeArea(histogram));
        }
        
        return ans;
    }
};