class DisJoint{
  vector<int> par,size;
  int compo;
public:
    DisJoint(int n){
      par.resize(n+1);
      size.resize(n+1,1);
      compo=0;
      for(int i=0;i<n+1;i++){
        par[i]=i;
      }
    }

    int getUParent(int n){
      if(n  == par[n]) return n;
      return par[n] = getUParent(par[n]);
    }

    void unionS(int a , int b){
      int ulpa = getUParent(a);
      int ulpb = getUParent(b);
      if( ulpa == ulpb) return;
      if( size[ulpa] > size[ulpb]){
        par[ulpb] = ulpa;
        size[ulpa] += size[ulpb];
      }
      else{
        par[ulpa] = ulpb;
        size[ulpb]+=size[ulpa];
      }
    }
    
    int findNumberOfComponents(){
      for(int i=0;i<par.size()-1;i++){
        if(par[i]==i) compo++;
      }
      return compo;
    }

};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
      DisJoint ds(n);
      if(connections.size() <n-1) return -1;
      int cnt=0;
        for(auto pair: connections){
          int x = ds.getUParent(pair[0]);
          int y = ds.getUParent(pair[1]);
          if(x!=y){
            ds.unionS(x,y);
          } 
        }
        int compo = ds.findNumberOfComponents();
        return compo-1;
    }
};