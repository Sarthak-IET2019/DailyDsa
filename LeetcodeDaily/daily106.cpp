// Count Unreachable Pairs of Nodes in an Undirected Graph


class Solution {
public: 
    void solve(vector<int>adj[],vector<int>&vis,int node,int &tempans){
        
        vis[node]=1;

        for(auto it:adj[node]){
            if(!vis[it]){
                tempans++;
                solve(adj,vis,it,tempans);
            }
        }
    }


    long long countPairs(int n, vector<vector<int>>& edges) {

        vector<int>adj[n];
        vector<int>vis(n,0);
        long long ans=0;
        long long total_nodes=0;

        for(auto i:edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0;i<n;++i){
            if(!vis[i]){
                int tempans=1;
                solve(adj,vis,i,tempans);
                cout<<tempans<<endl;
                ans+=(total_nodes*tempans);
                total_nodes+=tempans;
            }
        }

        return ans;


        
    }
};