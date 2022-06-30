class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size() , m = image[0].size();
        int currColor = image[sr][sc];
        image[sr][sc] = color;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        vector<vector<int>> c(n,vector<int>(m,0));
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        while(!q.empty()){
            auto curr = q.front();
            int x = curr.first , y = curr.second;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nx = x+dx[i], ny = y+dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || c[nx][ny] == 1 || image[nx][ny] != currColor)continue;
                // image[nx][ny] = $;
                image[nx][ny] = color;
                c[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
        
        return image;
    }
};