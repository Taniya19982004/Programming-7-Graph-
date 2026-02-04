#include<bits/stdc++.h>
using namespace std;
class Solution {
    
   void dfs_1(int node,vector<int>&vis, vector<int> &ls,vector<vector<int>>& adj){
        vis[node]=1;
        ls.push_back(node);
        
        for(auto it:adj[node]){
            if(!vis[it]){
                 dfs_1(it,vis,ls,adj);
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int>vis(n,0);
        vector<int>ls;
        int node = 0;
        dfs_1(node,vis,ls,adj);
        return ls;
    }
};


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n); 

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;
    vector<int> res = obj.dfs(adj);

    cout << "DFS Traversal:\n";
    for(int x : res) cout << x << " ";
}
