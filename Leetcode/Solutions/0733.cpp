class Solution {
public:
    void solve(vector<vector<int>> &image,int i,int j,int m,int n,int val,int color){
      if(i==-1 || j==-1 || i==m || j==n || image[i][j] == color||image[i][j]!=val) return;
      // cout<<i<<j<<endl;
      image[i][j]=color;
      solve(image,i+1,j,m,n,val,color);
      solve(image,i-1,j,m,n,val,color);
      solve(image,i,j+1,m,n,val,color);
      solve(image,i,j-1,m,n,val,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      int m=image.size();
      int n=image[0].size();
      int val=image[sr][sc];
      solve(image,sr,sc,m,n,val,color);
      return image;
    }
};