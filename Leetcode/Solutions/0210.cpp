class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> que;
        int n = numCourses;
        vector<int> adj[n];
        for(auto pre:prerequisites){
          int i = pre[0];
          int j = pre[1];
          adj[j].push_back(i);
        }
      
        vector<int> vis(n,0);
        vector<int> indeg(n,0);
        vector<int> topo;
        for(auto row: adj){
          for(auto elem : row){
            indeg[elem]++;
          }
        }
        
        for(int i=0;i<n;i++){
          if(indeg[i]==0) que.push(i);
        }
        while(!que.empty()){
          int elem = que.front();
          que.pop();
          topo.push_back(elem);
          for(auto it:adj[elem]){
            indeg[it]--;
            if(indeg[it]==0) que.push(it);
          }
        }
        if(topo.size()  <  numCourses) return {};
        return topo;
    }
};