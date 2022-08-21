class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans = 0;
        int sum = 0;
        for(int i=0;i<energy.size();i++){
            sum += energy[i];
        }
        
        if(sum>=initialEnergy){
            ans += sum-initialEnergy+1;
        }
        
        
        for(int i=0;i<experience.size();i++){
            if(initialExperience>experience[i]){
                initialExperience += experience[i];
            }else{
                ans += experience[i] - initialExperience + 1;
                initialExperience += (experience[i] - initialExperience + 1) + experience[i];
            }
        }
        
        return ans;
        
    }
};