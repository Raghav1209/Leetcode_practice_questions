class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int> count1(26,0);
        vector<int> count2(26,0);
        int j = 0;
        int ele;
        int swaps = 0;
        // int k = 0;
        for(int i=0;i<n;i++){
            count1[tops[i]]++;
        }
        
        for(int i=0;i<n;i++){
            count2[bottoms[i]]++;
        }
        
        int maxx1 = *max_element(count1.begin(),count1.end());
        int maxx2 = *max_element(count2.begin(),count2.end());
        
        if(maxx1>=maxx2){
                for(auto x : count1){
                if(x == maxx1){
                    ele = j;
                    break;
                }
                j++;
            }
        }else{
            for(auto x : count2){
            if(x == maxx2){
                ele = j;
                break;
            }
            j++;
        }
        }
        
        if(maxx1>=maxx2){
            for(int i=0;i<n;i++){
                if(tops[i]!=ele){
                    if(bottoms[i]==ele){
                        // swap(tops[i],bottoms[i]);
                        swaps++;
                    }else{
                        return -1;
                    }
                }
            }
        }else{
            for(int i=0;i<n;i++){
                if(bottoms[i]!=ele){
                    if(tops[i]==ele){
                        // swap(tops[i],bottoms[i]);
                        swaps++;
                    }else{
                        return -1;
                    }
                }
            }
        }
        
        return swaps;
        
        
        
    }
};