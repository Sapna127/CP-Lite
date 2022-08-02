//memoization

 int f(vector<vector<int>>& grid, int r, int c, vector<vector<int>> &dp){
        if(r<0||c<0) return INT_MAX;
        else if(r==0&&c==0) return grid[r][c];
        if(dp[r][c]!=-1) return dp[r][c];
        int res = min(f(grid,r-1,c,dp),f(grid,r,c-1,dp))+grid[r][c];
        dp[r][c]=res;
        return res;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(grid,m-1,n-1,dp);
    }

//TC O( n*m )
//SC O(n*m) + O(n)

//tabulation

int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
      
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) dp[i][j]=grid[0][0];
                else{
                      int l = grid[i][j], u = grid[i][j];
                    if(i>0) l += dp[i-1][j];
                    else l+=1e9;
                    if(j>0) u += dp[i][j-1];
                    else u+=1e9;
                    dp[i][j] = min(l,u);
                }
            }
        }
        return dp[n-1][m-1];
    }
//TC O( n*m )
//SC O(n*m) 

//space optimization

int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        //vector<vector<int>> dp(n,vector<int>(m,0));
        vector<int> prev(m,0);
    for(int i=0; i<n ; i++){
        vector<int> curr(m,0);
        for(int j=0; j<m; j++){
            if(i==0 && j==0) curr[j] = grid[i][j];
            else{
                
                int up = grid[i][j];
                if(i>0) up += prev[j];
                else up += 1e9;
                
                int left = grid[i][j];
                if(j>0) left+=curr[j-1];
                else left += 1e9;
                
                curr[j] = min(up,left);
            }
        }
        prev=curr;
    }
    
    return prev[m-1];
    }
//TC O( n*m )
//SC O(m) 


