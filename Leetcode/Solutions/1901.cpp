TC: 0(nlog(m));
SC: 0(1)

class Solution {
public:
int findMax(vector<vector<int>> &mat,int n,int m, int mid){
  int max=-1;
  int index=-1;
  for(int i=0;i<n;i++){
    if(mat[i][mid]>max){
      max=mat[i][mid];
      index=i;
    }
  }
  return index;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int start=0;
        int end=mat[0].size()-1;
        int n=mat.size();
        int m=mat[0].size();
        while(start<=end){
          int mid=start+(end-start)/2;
          int index=findMax(mat,n,m,mid);
          int left=INT_MIN;
          int right=INT_MIN;
          mid-1>=0 ? left=mat[index][mid-1]: -1;
          mid+1<m ? right=mat[index][mid+1] : -1;
          int value=mat[index][mid];
          if(value>left && value> right){
            return {index,mid};
          }
          else if(value<left) end=mid-1;
          else if(value<right) start=mid+1;
        }
        return {-1,-1};
    }
};