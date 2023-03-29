//Minimum Cost For Tickets


class Solution {
public:
    
    int solve(vector<int>&days,vector<int>&costs,vector<int>&dp,int n,int ind){
        
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int op1 = costs[0]+solve(days,costs,dp,n,ind+1);

        int i;
        for(i=ind;i<n and days[i]<days[ind]+7;++i);
        int op2 = costs[1]+ solve(days,costs,dp,n,i);
        
        for(i=ind;i<n and days[i]<days[ind]+30;++i);
        int op3 = costs[2]+ solve(days,costs,dp,n,i);


        return dp[ind]=min({op1,op2,op3});
        
    
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        vector<int>dp(n,-1);
        return solve(days,costs,dp,n,0);
    }
};