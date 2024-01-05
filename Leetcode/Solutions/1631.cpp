class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
      priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pque;
      pque.push({0,{0,0}});
      vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
      dist[0][0]=0;
      int drow[]= {-1,0,1,0};
      int dcol[]={0,1,0,-1};
      while( !pque.empty() ){
          int val = pque.top().first;
          int row= pque.top().second.first;
          int col = pque.top().second.second;
          pque.pop();
          for(int i=0;i<4;i++){
              int nrow=drow[i]+row;
              int ncol=dcol[i]+col;
              if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                  int newVal = max(val,abs(heights[row][col] - heights[nrow][ncol]));
                  if(dist[nrow][ncol] > newVal){
                      dist[nrow][ncol] =newVal;
                      pque.push({newVal,{nrow,ncol}});
                  }
              }
          }
      }
      if(dist[n-1][m-1]==INT_MAX) return -1;
      return dist[n-1][m-1];

    }
};