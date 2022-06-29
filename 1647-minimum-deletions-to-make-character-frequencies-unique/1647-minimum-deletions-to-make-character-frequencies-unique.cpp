class Solution {
public:
    int minDeletions(string s) {
        sort(s.begin(),s.end());
        int count = 0;
        map<char,int> mp1;
        map<int,char> mp2;
        
        for(int i=0;i<s.size();i++){
            mp1[s[i]]++;
        }
        
        for(auto x : mp1){
            if(mp2.find(x.second)==mp2.end()){
                mp2[x.second] = x.first;
            }else{
                int y = x.second;
                while(x.second){
                    if(mp2.find(x.second-1)==mp2.end()){
                        if((x.second-1)!=0)
                        {
                            mp2[x.second-1] = x.first;
                        }
                       
                        int xx = x.second-1;
                        count = count+(y-xx) ;
                        break;
                    }
                    x.second--;
                }
            }
        }
        
        // for(auto x : mp1){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        
        return count;
        
        
        
    }
};