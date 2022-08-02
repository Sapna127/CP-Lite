//memoization
int f(int idx, int buy, vector<int> &prices, int n, vector<vector<int>> &dp){
        if(idx==n) return 0;
        
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[idx]+f(idx+1,0,prices,n,dp) , f(idx+1,1,prices,n,dp));
        }
        else{
            profit = max(prices[idx]+f(idx+1,1,prices,n,dp), f(idx+1,0,prices,n,dp));
        }
        
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return f(0,1,prices,n,dp);
    }
//TC O(N*2) 
//Sc O(N*2) + O(N)

//tabulation
int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        dp[n][0]=dp[n][1]=0;
        
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
             int profit = 0;
            if(buy){
                profit = max(-prices[idx]+dp[idx+1][0] , dp[idx+1][1]);
            }
            else{
                profit = max(prices[idx]+dp[idx+1][1], dp[idx+1][0]);
            }

            dp[idx][buy] = profit;    
                }
            }
            return dp[0][1];
    }
//TC O(N*2) 
//Sc O(N*2) 

//space optimization 2 arrays
 int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vector<vector<int>> dp(n+1, vector<int>(2,-1));
        vector<int> ahead(2,0), curr(2,0);
        ahead[0]=ahead[1]=0;
        
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
             int profit = 0;
            if(buy){
                profit = max(-prices[idx]+ahead[0] , ahead[1]);
            }
            else{
                profit = max(prices[idx]+ahead[1], ahead[0]);
            }

            curr[buy] = profit;    
                }
            ahead=curr;
            }
            return ahead[1];
    }
//TC O(N*2) 
//Sc O(1) 

//space optimization 4 variables
int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vector<vector<int>> dp(n+1, vector<int>(2,-1));
        //vector<int> ahead(2,0), curr(2,0);
        
        int aheadBuy, aheadNotBuy, currBuy, currNotBuy;
        aheadNotBuy=aheadBuy=0;
        
        for(int idx=n-1;idx>=0;idx--){
      
            currBuy = max(-prices[idx]+aheadNotBuy , aheadBuy);
            currNotBuy = max(prices[idx]+aheadBuy, aheadNotBuy);
            
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }

            return aheadBuy;
    }
//TC O(N*2) 
//Sc O(1) 
