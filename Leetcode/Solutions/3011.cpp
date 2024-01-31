class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int> res = nums;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> noOfBitsArr(n, 0);
        for (int i = 0; i < n; i++) {
            int num = res[i];
            int cnt = 0;
            while (num) {
                cnt += num & 1;
                num = num >> 1;
            }
            noOfBitsArr[i] = cnt;
        }

        int noOfBits = noOfBitsArr[0];
        int idx = 0;
        for (int i = 1; i < n; i++) {
            if (noOfBitsArr[i] == noOfBits) {
                continue;
            }
            sort(res.begin() + idx, res.begin() + i);
            noOfBits = noOfBitsArr[i];
            idx = i;
        }

        sort(res.begin() + idx, res.end());

        return nums == res;
    }
};