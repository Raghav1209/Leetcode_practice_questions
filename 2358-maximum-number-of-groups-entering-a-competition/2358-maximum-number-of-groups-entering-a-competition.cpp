class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int ans = 0;
        sort(grades.begin(),grades.end());
        int count = 1;
        for(int i=0;i<grades.size();i=i+count){
            
            ans++;
            count++;
            
        }
        
        return ans;
        
    }
};