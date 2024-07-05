class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> edgeCount;
        for(auto edge:edges){
            edgeCount[edge[0]]++;
            edgeCount[edge[1]]++;
        }
        for(auto nodeCount:edgeCount){
            if(nodeCount.second == edgeCount.size()-1){
                return nodeCount.first;
            }
        }
        return -1;

    }
};