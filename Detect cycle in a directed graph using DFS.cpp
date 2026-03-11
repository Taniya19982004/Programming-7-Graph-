#include<bits/stdc++.h>
using namespace std;
class Solution {
    
    bool dfs(int node, int vis[], vector<int> adj[], int path_vis[]){
        vis[node]=1;
        path_vis[node]=1;
        
        for(auto it : adj[node]){
            
            if(!vis[it]){
                if(dfs(it,vis,adj,path_vis)==true){
                    return true;
                }
            }
            else if(path_vis[it]){
                return true;
            }
        }
        
     path_vis[node] = 0;
        return false;
    }


  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>adj[V];
        int vis[V] = {0};
        int path_vis[V] = {0};
         
        for(auto e: edges){
            
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            
        }
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,adj,path_vis)==true)
                   return true;
            }
        }
        
        return false;
    }
};

int main() {
    
    int V = 4;
    
    vector<vector<int>> edges = {
        {0,1},
        {1,2},
        {2,3},
        {3,1}
    };

    Solution obj;

    if(obj.isCyclic(V, edges))
        cout << "Cycle Detected";
    else
        cout << "No Cycle";

    return 0;
}