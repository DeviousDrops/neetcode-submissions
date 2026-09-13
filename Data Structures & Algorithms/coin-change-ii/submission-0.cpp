class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        vector<vector<unsigned long long>> dp(coins.size()+1,vector<unsigned long long>(amount+1,0));
        for(int i=1;i<coins.size()+1;i++)
            dp[i][0]=1;
        for(int i=1;i<coins.size()+1;i++){
            for(int j=1;j<amount+1;j++){
                unsigned long long posb=0;
                if(j-coins[i-1]>=0)
                    posb=dp[i][j-coins[i-1]];
                dp[i][j]=dp[i-1][j]+posb;
            }
        }    
        return dp[coins.size()][amount];
    }
};