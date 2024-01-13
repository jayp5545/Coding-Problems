

class DisJointSet{
	vector<int> rank,size,parent;
public:
	DisJointSet(int n){
		rank.resize(n+1,0);
		size.resize(n+1,1);
		parent.resize(n+1);
		for(int i=0;i<=n;i++){
			parent[i]=i;
		}
	}
	int findUParent(int node){
		if(parent[node] == node) return node;
		return parent[node]=findUParent(parent[node]);
	}
	void unionBySize(int u,int v){
		int ulp_u=findUParent(u);
		int ulp_v= findUParent(v);
		if(ulp_v==ulp_u) return;
		if(size[ulp_u] > size[ulp_v]){
			parent[ulp_v]=ulp_u;
			size[ulp_u]+=size[ulp_v];
		}
		else{
			parent[ulp_u]=ulp_v;
			size[ulp_v]+=size[ulp_u];
		}
	}
// }
	void unionByRank(int u,int v){
		int ulp_u=findUParent(u);
		int ulp_v= findUParent(v);
		if(ulp_v==ulp_u) return;
		if(rank[ulp_u] > rank[ulp_v]){
			parent[ulp_v]=ulp_u;
		}
		else if(rank[ulp_v] > rank[ulp_u]){
			parent[ulp_u]=ulp_v;
		}
		else{
			parent[ulp_v]=ulp_u;
			rank[ulp_u]++;
		}
	}
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0;
        int maxCol=0;
        for(auto it:stones){
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }
        DisJointSet ds(maxRow+maxCol+1);
        unordered_map<int,int> stoneNodes;
        for(auto it:stones){
            int rowNode=it[0];
            int colNode=it[1]+maxRow+1;
            ds.unionBySize(rowNode,colNode);
            stoneNodes[rowNode]=1;
            stoneNodes[colNode]=1;
        }
        int cnt=0;
        for(auto it : stoneNodes){
            if(ds.findUParent(it.first)==it.first) cnt++;
        }
        return stones.size()-cnt;
    }
};