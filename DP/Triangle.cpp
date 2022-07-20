//memoization
int f(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        int n = triangle.size();
        if(i==n-1) {return triangle[n-1][j];}
        if(dp[i][j]!=-1) return dp[i][j];
        int d = f(i+1,j,triangle, dp) + triangle[i][j];
        int dg = f(i+1,j+1,triangle, dp) + triangle[i][j];
        return dp[i][j] = min(d,dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return f(0,0,triangle,dp);
    }
//TC O(n*n)
// Sc O(n*n) + O(n)

//tabulation
 int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int j=0;j<n;j++) dp[n-1][j] = triangle[n-1][j];
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                 int d = dp[i+1][j] + triangle[i][j];
                 int dg = dp[i+1][j+1] + triangle[i][j];
            dp[i][j] = min(d,dg);
            }
        }
        return dp[0][0];
    }
//TC O(n*n)
// Sc O(n*n) 

//space optimization
 int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        //vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> front(n,0);
        vector<int> curr(n,0);
        for(int j=0;j<n;j++) front[j] = triangle[n-1][j];
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                 int d = front[j] + triangle[i][j];
                 int dg = front[j+1] + triangle[i][j];
            curr[j] = min(d,dg);
            }
            front = curr;
        }
        return front[0];
    }
//TC O(n*n)
// O(n)
