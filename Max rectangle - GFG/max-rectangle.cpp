// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
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
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int result = 0;
        vector<int> row(m);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(M[i][j] == 1){
                    row[j] += 1;
                }
                else {
                    row[j] = 0;
                }
            }
            result = max(result,LargeArea(row));
        }
        
        return result;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends