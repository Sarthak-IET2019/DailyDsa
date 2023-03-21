class Solution {
public:
    bool inword(string &a, string &b){

        if(b.size()-a.size()!=1) return 0;
        int j=0;

        for(int i=0;i<b.size();++i){
            if(a[j]==b[i]){
                j++;
            }

            if(j==a.size()) return 1;

        }

        return 0;
    }
    int solve(vector<string>&words,vector<vector<int>>&dp,int pi,int ind){

        if(ind==words.size()) return 0;
        if(dp[pi+1][ind]!=-1) return dp[pi+1][ind];

        int temp=INT_MIN;
        if(pi==-1 or inword(words[pi],words[ind])){
            temp= max(1+solve(words,dp,ind,ind+1),solve(words,dp,pi,ind+1));
        }

        else temp=solve(words,dp,pi,ind+1);

        return dp[pi+1][ind]=temp;
    }
    int longestStrChain(vector<string>& words) {

        int pi=-1;
        // sort(words.begin(),words.end());

        vector<string>ans;
        vector<pair<int,string>>temp;
        int n = words.size();
        vector<vector<int>>dp(n+1,vector<int>(n,-1));

        for(auto i:words) temp.push_back({i.size(),i});
        sort(temp.begin(),temp.end());

        for(auto i:temp) ans.push_back(i.second);

        

        return solve(ans,dp,pi,0);
        
    }
};