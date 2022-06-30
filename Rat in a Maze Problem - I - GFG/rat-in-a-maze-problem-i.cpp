// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    
    void dfs(vector<vector<int>> m,int n,string ds,int i,int j,vector<vector<bool>> &vis){
        if(i < 0 || j < 0 || i>=n || j>=n || m[i][j] == 0 || vis[i][j] == 1)return;
        if(i == n-1 && j == n-1){
            ans.push_back(ds);
            return ;
        }
        
        vis[i][j] = 1;
        
        dfs(m,n,ds+"U",i-1,j,vis);
        dfs(m,n,ds+"D",i+1,j,vis);
        dfs(m,n,ds+"R",i,j+1,vis);
        dfs(m,n,ds+"L",i,j-1,vis);
        
        vis[i][j] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string ds;
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        dfs(m,n,"",0,0,vis);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends