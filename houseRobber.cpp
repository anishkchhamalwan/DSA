class Solution {
    int helper(vector<int> nums, int i,vector<int> &dp){
        if(i==0 ) return nums[i];
        if(i==1) return max(nums[0],nums[1]);
        if(dp[i] !=-1) return dp[i];
        int take = nums[i] + helper(nums,i-2,dp);
        int nottake = helper(nums,i-1,dp);
        return dp[i] = max(take,nottake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return helper(nums,n-1,dp);
    }
};
