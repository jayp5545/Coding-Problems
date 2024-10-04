class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        if(n==2){
            return skill[0]*skill[1];
        }
        long long ans=0;
        sort(skill.begin(),skill.end());
        long long tSum = accumulate(skill.begin(),skill.end(),0); 
        int i=0,j=n-1;
        int noOfTeams = n/2;
        int dSum = tSum/noOfTeams;
        while(i<j){
            int tempSum=skill[i]+skill[j];
            if(tempSum!=dSum) return -1;
            ans+=(skill[i]*skill[j]);
            i++;
            j--;
        }
        return ans;
    }
};