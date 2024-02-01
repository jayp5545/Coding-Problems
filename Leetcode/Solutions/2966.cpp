class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        int currElem=-1;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            vector<int> arr;
            int cnt=0;
            currElem = nums[i];
            arr.push_back(currElem);
            while( cnt != 2){
                i++;
                if( abs(nums[i] - currElem) <= k){
                    arr.push_back( nums[i] );
                }
                else{
                    return {};
                }
                cnt++;
            }
            ans.push_back(arr);
        }

        return ans;

    }
};