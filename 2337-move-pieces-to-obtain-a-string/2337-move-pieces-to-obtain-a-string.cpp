class Solution {
public:
    bool canChange(string start, string target) {
        
        string a,b;
        
        for(int i=0;i<start.size();i++){
            if(start[i]!='_'){
                a.push_back(start[i]);
            }
        }
        
         for(int i=0;i<target.size();i++){
            if(target[i]!='_'){
                b.push_back(target[i]);
            }
        }
        
        if(a!=b){
            return false;
        }
        
        vector<int> l1,l2,r1,r2;
        for(int i=0;i<start.size();i++){
            if(start[i]=='L'){
                l1.push_back(i);
            }
            if(start[i]=='R'){
                r1.push_back(i);
            }
            if(target[i]=='L'){
                l2.push_back(i);
            }
            if(target[i]=='R'){
                r2.push_back(i);
            }
        }
        
        for(int i=0;i<l1.size();i++){
            if(l1[i]<l2[i]){
                return false;
            }
        }
        
         for(int i=0;i<r1.size();i++){
            if(r1[i]>r2[i]){
                return false;
            }
        }
        
        return true;
        
    }
};