// 1402. Reducing Dishes

/*
we have ignored an essential part of the problem. We are iterating the dishes in order, say left to right or vice versa, but the problem doesn't have any constraint on the order. 
The dishes can be cooked in any order, so iterating from left to right will not always work. Can we greedily arrange them in order so that iterating them from left to right always works? 
Remember the time taken for a dish is equal to the number of dishes that have been cooked + 1; hence if we want to maximize the sum, we need to ensure that the dishes with high satisfaction value get cooked later as they will be multiplied by a larger time coefficient. 
This implies that if we sort the dishes in ascending order of their satisfaction value, we should cook them from left to right. Hence, we will first sort the dishes and then apply the algorithm that we just discussed.
*/

class Solution {
public:

    int solve(vector<int>&arr,vector<vector<int>>&dp,int n, int ind,int fac){

        if(ind==n) return 0;
        if(dp[ind][fac]!=-1) return dp[ind][fac];

        int temp = INT_MIN;

        temp = max(arr[ind]*fac+solve(arr,dp,n,ind+1,fac+1),solve(arr,dp,n,ind+1,fac));

        return dp[ind][fac]=temp;
       

    }

    int maxSatisfaction(vector<int>& arr) {
        
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>vis(n,vector<int>(n+1,-1));
        return solve(arr,vis,n,0,1);
    }
};