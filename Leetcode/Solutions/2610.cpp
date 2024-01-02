class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int  n=nums.size();
        unordered_map<int,int> freq;
        vector<vector<int>> result;
        for(int i=0;i<n;i++){
            int fre=freq[nums[i]];
            if(fre==result.size()) result.push_back({});
            result[fre].push_back(nums[i]);
            freq[nums[i]]++;
        }
        return result;
    }
};