class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        map<int,int> temp;
        int sum=0;
        for(int i=0;i<cardPoints.size();i++){
          sum+=cardPoints[i];
          temp[i]=sum;
        }
        temp[-1]=0;
        if(k==cardPoints.size()) return sum;
        int val=cardPoints.size()-k;
        int i=0;
        int j=val-1;
        int ans=INT_MIN;
        int iSum=0;
        while(j<cardPoints.size()){
          int jSum=temp[j];
          int windowSum=jSum-iSum;
          int actualSum=sum-windowSum;
          ans=max(ans,actualSum);
          iSum+=cardPoints[i];
          i++;
          j++;
        }
        return ans;
    }
};