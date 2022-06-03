class Solution {
public:
    // Intial     Middle    Final
    // 0            -1         1
    // 1            -2         0
    
    int dx[8] = {0,0,1,-1,1,-1,1,-1};
    int dy[8] = {1,-1,0,0,1,1,-1,-1};
        
    void check0(int i , int j , int n , int m ,vector<vector<int>> &board){
        int count = 0;
        
        for(int k = 0; k < 8; k++){
            int x = i+dx[k] , y = j+dy[k];
            if(x < 0 || y < 0 || x >= n || y >= m)continue;
            if(board[x][y] == 1 || board[x][y] == -2)count++;
        }
        
        if(count == 3){
            board[i][j] = -1; 
        }
    }
    
    void check1(int i , int j , int n , int m , vector<vector<int>> &board){
        int count = 0;
        
        for(int k = 0; k < 8; k++){
            int x = i+dx[k] , y = j+dy[k];
            if(x < 0 || y < 0 || x >= n || y >= m)continue;
            if(board[x][y] == 1 || board[x][y] == -2)count++;
        }
        if(count > 3 || count < 2){
            board[i][j] = -2;
        }
        
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size() , m = board[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 0 || board[i][j] == -1){
                    check0(i,j,n,m,board);
                } else {
                    check1(i,j,n,m,board);
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == -2)board[i][j] = 0;
                if(board[i][j] == -1)board[i][j] = 1;
            }
        }
    };
};