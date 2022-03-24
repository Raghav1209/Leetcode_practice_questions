class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(),people.end());
        for(auto x : people){
            cout<<x<<" ";
        }
        cout<<endl;
        int boat = 0;
        int low = 0;
        int high = people.size()-1;
        
        while(low<=high){
            if(people[low]+people[high]<=limit){
                boat++;
                low++;
                high--;
            }else{
                boat++;
                high--;
            }
        }
        
        return boat;
        
    }
};