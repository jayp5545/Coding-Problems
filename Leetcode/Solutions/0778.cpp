class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n  = grid.size();
        int maxans=INT_MIN;
        vector<vector<int>> dist(n,vector<int> (n,INT_MAX));
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pque;
        pque.push({grid[0][0],{0,0}});

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while( !pque.empty() ){
          int k = pque.top().second.first;
          int j = pque.top().second.second;
          int dis = pque.top().first;
          maxans=max(maxans,dis);
          dist[k][j] = dis;
          if( k==n-1 && j==n-1) return maxans;
          pque.pop();
          for(int i=0;i<4;i++){
            int nrow = drow[i]+k;
            int ncol = dcol[i]+j;
            if( nrow>=n || ncol>=n || nrow<0 || ncol<0) continue;
            int val = dist[nrow][ncol];
            int newDist = max(maxans,grid[nrow][ncol]);
            if( val> newDist){
              dist[nrow][ncol] = newDist;
              pque.push({newDist,{nrow,ncol}});
              }
          }
        }
        return maxans;
    }
};