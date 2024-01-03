class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0;
        int curr=-1;
        int n=bank.size();
        int m=bank[0].size();
        vector<int> rowWiseCnt;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                if(bank[i][j]=='1') cnt++;
            }
            // cout<<cnt<<endl;
            rowWiseCnt.push_back(cnt);
        }
        for(int i=0;i<n;i++){
            if(rowWiseCnt[i]!=0){
                if(curr !=- 1) ans+=curr*rowWiseCnt[i];
                curr=rowWiseCnt[i];
            }
        }
        return ans;
    }
};