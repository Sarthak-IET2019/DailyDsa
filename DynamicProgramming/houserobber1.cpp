class Solution {
public:

    int solve(vector<int>&nums,vector<int>&dp,int n){


        if(n<0) return 0;
        if(n==0) return nums[n];
        if(dp[n]!=-1) return dp[n];
        dp[n]=INT_MIN;

        dp[n]=max(nums[n]+solve(nums,dp,n-2),solve(nums,dp,n-1));

        return dp[n];
    }

    int rob(vector<int>& nums) {

        int n= nums.size();
        vector<int>dp(n,-1);

        return solve(nums,dp,n-1);
        
    }
};