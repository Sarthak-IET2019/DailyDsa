//Number of Operations to Make Network Connected

class Solution {
public:

    void dfs(vector<int>adj[],vector<int>&vis,int node){

        vis[node]=1;

        for(auto it:adj[node]){
            if(!vis[it]){
                
                dfs(adj,vis,it);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {

        vector<int>vis(n,0);
        vector<int>adj[n];
        int cabels=connections.size();

        int com=0;

        for(auto i:connections){
            int u = i[0];
            int v= i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }

        for(int i=0;i<n;++i){
            if(!vis[i]){
            dfs(adj,vis,i);
            com++;
            }
        }

        if(cabels>=n-1){
            return com-1;
        }

        else return -1;
        
    }
};