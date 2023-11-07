class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int ans = 1;
        int time=1;
        vector<int> curr_time(dist.size());
        for(int i=0;i<dist.size();i++){
         curr_time[i]=(dist[i]/speed[i]) + (dist[i]%speed[i]!=0);
        }

        sort(curr_time.begin(), curr_time.end());
        for(int i=1;i<dist.size();i++){
          if(curr_time[i]-time <=0) return ans;
          ans++;
          time+=1;
        }
        return ans;
    }
};