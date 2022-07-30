 int maxProfit(vector<int>& prices, int fee) {
         int n = prices.size();
        
        int aheadBuy, aheadNotBuy, currBuy, currNotBuy;
        aheadNotBuy=aheadBuy=0;
        
        for(int idx=n-1;idx>=0;idx--){
      
            currBuy = max(-prices[idx]+aheadNotBuy , aheadBuy);
            currNotBuy = max(prices[idx]-fee+aheadBuy, aheadNotBuy);
            
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }

            return aheadBuy;
    }

//TC O(n*2)
//SC O(1)
