class Solution {
    bool wordexist;
public:
    void dfs(int r,int c,vector<vector<bool>> &grid,int n,int m,string word,int in,vector<vector<char>>&board)
    {
        
        grid[r][c] = true;
        if(in == word.size())
        {
            wordexist = true;
            return;
        }
        
        int x = r+1,y = c;
        if(x<n && grid[x][y]==false && board[x][y] == word[in])
        {
            dfs(x,y,grid,n,m,word,in+1,board);
            grid[x][y] = false;
        }
        
        if(wordexist)
            return;
        x = r-1;
        if(x>=0 && grid[x][y]==false && board[x][y] == word[in])
        {
            dfs(x,y,grid,n,m,word,in+1,board);
            grid[x][y] = false;
        }
        
        if(wordexist)
            return;
        y = c+1;
        x = r;
        if(y<m && grid[x][y]==false && board[x][y] == word[in])
        {
            dfs(x,y,grid,n,m,word,in+1,board);
            grid[x][y] = false;
        }
        
        if(wordexist)
            return;
        y =c-1;
        if(y>=0 && grid[x][y]==false && board[x][y] == word[in])
        {
            dfs(x,y,grid,n,m,word,in+1,board);
            grid[x][y] = false;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        wordexist = 0;
        int n=board.size(),m=board[0].size();
        vector<vector<bool>>grid(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == word[0])
                {
                    dfs(i,j,grid,n,m,word,1,board);
                    grid[i][j] = false;
                }
            }
        }
        return wordexist;
    }
};