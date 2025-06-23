class Solution {
  public:
    int helper(vector<int> height,int i,vector<int>& dp){
        if(i == 0) return 0;
        if(dp[i] != -1) return dp[i];
        int oneJump = helper(height,i-1,dp) +abs(height[i]-height[i-1]);
        int twoJump =INT_MAX;
        if(i>1) twoJump = helper(height,i-2,dp) + abs(height[i] - height[i-2]);
        return dp[i] = min(oneJump,twoJump);
    }
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n+1,-1);
        return helper(height,n-1,dp);
    }
};

