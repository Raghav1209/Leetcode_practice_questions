class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        vector<int> v1;
        vector<int> v2;
        string str = "";
        for(int i=0;i<version1.size();i++){
            
            if(version1[i]=='.'){
                v1.push_back(stoi(str));
                str = "";
            }else{
                str += version1[i];
            }
            
        }
         v1.push_back(stoi(str));
        str = "";
        
        for(int i=0;i<version2.size();i++){
            
            if(version2[i]=='.'){
                v2.push_back(stoi(str));
                str = "";
            }else{
                str += version2[i];
            }
            
        }
         v2.push_back(stoi(str));
        str = "";
        
        int n = v1.size();
        int m = v2.size();
        
        
        if(n<m){
            int k = n;
            while(k!=m){
                v1.push_back(0);
                k++;
            }
        }else{
            int k = m;
            while(k!=n){
                v2.push_back(0);
                k++;
            }
        }
        
        int i=0;
        // int j=0;
        int flag=1;
        
        while(i<v1.size()){
            if(v1[i]>v2[i]){
                return 1;
            }else if(v1[i]<v2[i]){
                return -1;
            }else{
                flag = 0;
                i++;
                // j++;
            }
        }
        
        if(flag==0){
            return 0;
        }else{
            return 1;
        }
        
        
    }
};