class Solution {
public:
    void dfs(int node, vector<vector<int>>&adj, vector<int>&vis,long long int &cnt){
        vis[node]=1;
        cnt++;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,cnt);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
         vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        long long int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            long long int cnt=0;
            if(!vis[i]){
                dfs(i,adj,vis,cnt);
                ans+=cnt*(n-cnt);
            }
        }
        return ans/2;
    }
};
