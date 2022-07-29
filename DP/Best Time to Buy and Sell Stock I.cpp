#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int mini=prices[0],maxProfit=0;
    int n = prices.size();
    for(int i=0;i<n;i++){
        maxProfit=max(maxProfit, prices[i]-mini);
        mini=min(mini,prices[i]);
    }
    return maxProfit;
}
