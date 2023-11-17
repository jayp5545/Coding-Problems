class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n , vector<int>(n,INT_MAX));
        int ans = INT_MAX;
        queue<  pair<int, pair<int,int>>> que; // dis ,{row , col}
        if( grid[0][0] == 0)  {
          que.push( {1, {0,0} } );
          dist[0][0] = 1;
        }
        int drw[]= {-1,0,1,0};
        int dco[] = {0,1,0,-1};
        
        while( !que.empty()){
          int dist1 = que.front().first;
          int row = que.front().second.first;
          int col = que.front().second.second;
          que.pop();
          for(int i=-1;i<2;i++){
            for(int j=-1;j<2;j++){
              int nrw = row + i;
              int nco = col + j;
              if(i==0 && j==0) continue;
              if(nrw >=n || nco>=n || nrw<0 || nco <0 || grid[nrw][nco]==1) continue;
              if(dist[nrw][nco] > dist1+1){
                que.push({dist1+1,{nrw,nco}});
                dist[nrw][nco] = dist1 + 1;
              }
            }
          }
        }
        if(dist[n-1][n-1] == INT_MAX) return -1;
        return dist[n-1][n-1];
    }
};