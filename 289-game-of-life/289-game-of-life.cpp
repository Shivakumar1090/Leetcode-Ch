class Solution {
public:
    int dx[8] = {0,0,1,-1,1,-1,1,-1};
    int dy[8] = {1,-1,0,0,1,1,-1,-1};
        
    void check0(int i , int j , int n , int m ,vector<vector<int>> &board , vector<vector<int>>&c){
        int count = 0;
        
        for(int k = 0; k < 8; k++){
            int x = i+dx[k] , y = j+dy[k];
            if(x < 0 || y < 0 || x >= n || y >= m)continue;
            if(c[x][y] == 1)count++;
        }
        
        if(count == 3){
            board[i][j] = 1;
        }
    }
    
    void check1(int i , int j , int n , int m , vector<vector<int>> &board , vector<vector<int>>& c){
        int count0 = 0, count1 = 0;
        
        for(int k = 0; k < 8; k++){
            int x = i+dx[k] , y = j+dy[k];
            
            if(x < 0 || y < 0 || x >= n || y >= m)continue;
            
            if(c[x][y] == 1)count1++;
        }
        if(count1 > 3 || count1 < 2){
            board[i][j] = 0;
        }
        
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size() , m = board[0].size();
        vector<vector<int>> c = board;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 0){
                    check0(i,j,n,m,board,c);
                } else {
                    check1(i,j,n,m,board,c);
                }
            }
        }
        
        
    };
};