class Solution {
public:
    
    int check(vector<int> &piles,int val){
        int hours = 0;
        for(int i=0;i<piles.size();i++){
            hours += piles[i]/val;
            if(piles[i]%val!=0){
                hours += 1;
            }
        }
        return hours;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        if(h==piles.size()){
            return piles[piles.size()-1];
        }
        int l = 1;
        int r = piles[piles.size()-1];
        while(l<=r){
            int mid = (l+r)/2;
            int k = check(piles,mid);
            if(k<=h){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};