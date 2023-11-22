class Solution {
public:
int checkIsValid( vector<int> &weights, int days, int mid){
    int sum=0;
    int totalDays=0;
    for(int i=0;i<weights.size();i++){
        sum+=weights[i];
        if(sum>mid){
            sum=weights[i];
            totalDays+=1;
        }    
    }   
    totalDays+=1;
    if(totalDays>days) return 0;
    return 1;
    // return 2;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int maxNumber=INT_MIN;
        int sum=0;
        int ans=-1;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>maxNumber) maxNumber=weights[i];
            sum+=weights[i];
        }
        int start=maxNumber;
        int end=sum;

        while(start<=end){
            int mid=start+(end-start)/2;
            bool isValid = checkIsValid(weights,days,mid);
            if(isValid==1){
                end=mid-1;
                ans=mid;
            }
            else{
              start=mid+1;
            }
            // if(!isValid==0){
            //     start=mid+1;
            // }
            // if(isValid==2){
            //     end=mid-1;
            // }
        }
        return ans;
    }
};