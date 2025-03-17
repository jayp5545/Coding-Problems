class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> numMap;
        int n = nums.size();
        for(int i=0;i<n;i++){
            numMap[nums[i]]++;
        }
        int cntPairs = 0;
        for(auto it: numMap){
            if(it.second%2!=0) return false;
            cntPairs+=(it.second/2);
        }
        return cntPairs == n/2;
    }
};