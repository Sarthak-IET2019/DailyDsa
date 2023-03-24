class Solution {
public:
    int solve(vector<int>&nums,vector<vector<int>>&dp,int pre,int curr){

        int n = nums.size();
        if(curr>=n) return 0;
        if(dp[pre+1][curr]!=-1) return dp[pre+1][curr];

        int temp= INT_MIN;
        if(pre==-1 or pre!=curr-1)
            temp = max(nums[curr]+solve(nums,dp,curr,curr+1),solve(nums,dp,pre,curr+1));
        else temp = solve(nums,dp,pre,curr+1);

        return dp[pre+1][curr]=temp;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<vector<int>>dp1(n,vector<int>(n,-1));
        vector<vector<int>>dp2(n,vector<int>(n,-1));

        vector<int>arr1,arr2;
        for(int i=0;i<n;++i){
            if(i!=0) arr1.push_back(nums[i]);
            if(i!=n-1) arr2.push_back(nums[i]);
        }

        int t = solve(arr1,dp1,-1,0);
        int s = solve(arr2,dp2,-1,0);

        return max(t,s);
    }
};