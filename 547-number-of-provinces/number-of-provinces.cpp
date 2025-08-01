class Solution {
public:
    void dfs(vector<vector<int>>&adj,int node,vector<int> &vis)
    {
       vis[node]=1;
       for(auto x:adj[node])
       {
         if(!vis[x])dfs(adj,x,vis);
       }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>>adj(isConnected.size());
        vector<int> vis(isConnected.size());
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                if(isConnected[i][j]==1 && i!=j) adj[i].push_back(j);
            }
        }
        int ans=0;
        for(int i=0;i<isConnected.size();i++)
        {
            if(!vis[i]) ans++;
            dfs(adj,i,vis);
        }
        return ans;

    }
};