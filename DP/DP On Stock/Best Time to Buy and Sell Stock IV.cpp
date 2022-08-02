int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<=k;cap++){
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
        return after[1][k]; 
    }

//TC o(n*2*3)
//SC O(1)
