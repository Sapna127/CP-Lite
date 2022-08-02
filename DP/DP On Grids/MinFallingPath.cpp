//memoization
int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp ){
     
        if(j<0 || j>=matrix[0].size()) return 1e7;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int u = f(i-1,j,matrix,dp) + matrix[i][j];
        int ld = f(i-1,j-1,matrix,dp) + matrix[i][j];
        int rd = f(i-1,j+1,matrix,dp) + matrix[i][j];
        return dp[i][j] = min({u,ld,rd});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        int mini = 1e7;
        for(int j=0;j<m;j++){
            mini = min(mini,f(n-1,j,matrix,dp));
        }
        return mini;
    }

//TC O(n*m)
//SC O(n*m) + O(n)

//Tabulation
int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp ){
     
        if(j<0 || j>=matrix[0].size()) return 1e7;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int u = f(i-1,j,matrix,dp) + matrix[i][j];
        int ld = f(i-1,j-1,matrix,dp) + matrix[i][j];
        int rd = f(i-1,j+1,matrix,dp) + matrix[i][j];
        return dp[i][j] = min({u,ld,rd});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        for(int i=0;i<m;i++) dp[0][i]=matrix[0][i];
        int mini = 1e7;
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
             int u = dp[i-1][j] + matrix[i][j];
             int ld = matrix[i][j];
             if(j-1>=0) ld+=dp[i-1][j-1];
             else ld+=1e7;
             int rd = matrix[i][j];    
             if(j+1<m) rd+=dp[i-1][j+1];
             else rd+=1e7;
             dp[i][j] = min({u,ld,rd});
            }
        }
        
        
        for(int j=0;j<m;j++){
            mini = min(mini,dp[n-1][j]);
        }
        return mini;
    }
//TC O(n*m) + O(n)
//SC O(n*m) + O(n)

//Space Optimization
    int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp ){
     
        if(j<0 || j>=matrix[0].size()) return 1e7;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int u = f(i-1,j,matrix,dp) + matrix[i][j];
        int ld = f(i-1,j-1,matrix,dp) + matrix[i][j];
        int rd = f(i-1,j+1,matrix,dp) + matrix[i][j];
        return dp[i][j] = min({u,ld,rd});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        //vector<vector<int>> dp(n, vector<int>(m,-1));
        vector<int> prev(m, 0);
        vector<int> curr(m, 0);
        for(int i=0;i<m;i++) prev[i]=matrix[0][i];
        int mini = 1e7;
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
             int u = prev[j] + matrix[i][j];
             int ld = matrix[i][j];
             if(j-1>=0) ld+=prev[j-1];
             else ld+=1e7;
             int rd = matrix[i][j];    
             if(j+1<m) rd+=prev[j+1];
             else rd+=1e7;
             curr[j] = min({u,ld,rd});
            }
            prev=curr;
        }
        
        
        for(int j=0;j<m;j++){
            mini = min(mini,prev[j]);
        }
        return mini;
    }
//TC O(n*m) + O(n)
//SC O(m)
