//memoization
int f(int idx, int buy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>>&dp){
        if(idx==n || cap==0) return 0;

        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        if(buy){
            return max(-prices[idx]+f(idx+1,0,cap,prices,n,dp), f(idx+1,1,cap,prices,n,dp));
        }
        return max(prices[idx]+f(idx+1,1,cap-1,prices,n,dp) , f(idx+1,0,cap,prices,n,dp));
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return f(0,1,2,prices,n,dp); 
    }

//TC O(N*2*3) 
//SC O(N*2*3) + O(N)

//tabulation
 int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<3;cap++){
                if(buy){
                    dp[idx][buy][cap] = max(-prices[idx]+dp[idx+1][0][cap], dp[idx+1][1][cap]);
                }
                else{
                    dp[idx][buy][cap] = max(prices[idx]+dp[idx+1][1][cap-1] , dp[idx+1][0][cap]);  
                }              
              }
            }
        }
        return dp[0][1][2]; 
    }
//TC O(N*2*3) 
//SC O(N*2*3) 

//space optimization 
int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<3;cap++){
                if(buy){
                    curr[buy][cap] = max(-prices[idx]+after[0][cap], after[1][cap]);
                }
                else{
                    curr[buy][cap] = max(prices[idx]+after[1][cap-1] , after[0][cap]);  
                }              
              }
            }
            after = curr;
        }
        return after[1][2]; 
    }
//TC O(N*2*3) 
//SC O(1)

//method - 2
//space optimization - we need only 2 transactions

//memoization
int f(int idx, int buy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>>&dp){
        if(idx==n || cap==0) return 0;

        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        if(buy){
            return max(-prices[idx]+f(idx+1,0,cap,prices,n,dp), f(idx+1,1,cap,prices,n,dp));
        }
        return max(prices[idx]+f(idx+1,1,cap-1,prices,n,dp) , f(idx+1,0,cap,prices,n,dp));
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return f(0,1,2,prices,n,dp); 
    }

//tabulation
int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<3;cap++){
                if(buy){
                    dp[idx][buy][cap] = max(-prices[idx]+dp[idx+1][0][cap], dp[idx+1][1][cap]);
                }
                else{
                    dp[idx][buy][cap] = max(prices[idx]+dp[idx+1][1][cap-1] , dp[idx+1][0][cap]);  
                }              
              }
            }
        }
        return dp[0][1][2]; 
    }

//space optimization
int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(5, 0) , curr(5,0);
        
        //for(int i=0;i<n;i++) dp[i][4]=0;
        //for(int t=0;t<4;t++) dp[n][t]=0;
        
        for(int idx=n-1;idx>=0;idx--){
            for(int trans=3;trans>=0;trans--){
              if(trans%2==0){
            curr[trans] = max(-prices[idx]+ahead[trans+1], ahead[trans]);
        }
        else{
            curr[trans] = max(prices[idx]+ahead[trans+1], ahead[trans]);
          }  
         }
        ahead=curr;
        }
        return curr[0];
    }
