class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    vector<vector<bool>> v;
    
    bool dfs(int x,int y ,vector<vector<char>> &board , string word ,int indx){
        if(indx == word.size())return true;
        
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != word[indx])return false;
        
        board[x][y] = '0';
        
        bool status = dfs(x-1,y,board,word,indx+1)||
                        dfs(x,y-1,board,word,indx+1)||
                        dfs(x+1,y,board,word,indx+1)||
                        dfs(x,y+1,board,word,indx+1);
        
        board[x][y] = word[indx];
        
        return status;
    }
    bool exist(vector<vector<char>>& board, string word) {
        queue<pair<int,int>> q;
        int n = board.size() , m = board[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(word[0] == board[i][j] && dfs(i,j,board,word,0)){
                    return true;
                }
            }
        }
        
        return false;
    }
};