//memoization
int f(int i, int j, string &s,string &t, vector<vector<int>> &dp){
        if(j==0) return 1;
        if(i==0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1]){
           return  dp[i][j] = f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp);
        }
        return dp[i][j] = f(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n= s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return f(n,m,s,t,dp);
    }

//TC O(m*n)
//SC O(m*n)

//tabulation
int mod = 1e9+7;
    int numDistinct(string s, string t) {
        int n= s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
              if(s[i-1]==t[j-1])
                   dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
              else   dp[i][j] = dp[i-1][j];
        }
        }
        return (int)dp[n][m];
    }

//space optimization 2 arrays
 int mod = 1e9+7;
    int numDistinct(string s, string t) {
        int n= s.size(), m = t.size();
        //vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> prev(m+1,0) , curr(m+1,0);
        prev[0]=curr[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
              if(s[i-1]==t[j-1])
                   curr[j] = (prev[j-1] + prev[j])%mod;
              else   curr[j] = prev[j];
        }
            prev=curr;
        }
        return (int)curr[m];
    }

//space optimization 1 array
int mod = 1e9+7;
    int numDistinct(string s, string t) {
        int n= s.size(), m = t.size();
        //vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> prev(m+1,0);
        prev[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){ //reverse 
              if(s[i-1]==t[j-1])
                   prev[j] = (prev[j-1] + prev[j])%mod;
        }
        }
        return (int)prev[m];
    }
