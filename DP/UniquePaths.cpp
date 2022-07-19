//recursion
 int f(int m, int n){
        if(m==0 && n==0) return 1;
        if(m<0 || n<0) return 0;
        int up = f(m-1,n);
        int left = f(m,n-1);
        return up + left;
    }
    int uniquePaths(int m, int n) {
        return f(m-1,n-1);
    }

//TC O(2^(m*n))
//SC O(n-1 + m-1) + O(n)



//memoization
 int f(int m, int n, vector<vector<int>> &dp){
        if(m==0 && n==0) return 1;
        if(m<0 || n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int up = f(m-1,n,dp);
        int left = f(m,n-1,dp);
        return dp[m][n] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return f(m-1,n-1,dp);
    }
//TC O((m*n))
//SC O(n-1 + m-1) + O(n)

//tabulation
 int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1]; 
        return dp[m-1][n-1];
    }
//TC O((m*n))
//SC O(n-1 + m-1) 

//space optimization
int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0&&j==0) curr[i]=1;
                else{
                    int left=0,up=0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = left + up;
                }
           
            }
            prev=curr;
        }
        return prev[n-1];
    }
//TC O((m*n))
//SC O(n-1) 

//permutation

int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = m-1; // u can take n-1 as well
        double res = 1;
        for(int i=1;i<=r;i++){
            res = res * (N - r + i)/i;
        }
        return (int)res;
    }
//TC O(m-1) or O(n-1)
//SC O(1)
