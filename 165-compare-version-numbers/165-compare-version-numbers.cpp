class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        vector<int> v1;
        vector<int> v2;
        int flag;
        string str = "";
        for(int i=0;i<version1.size();i++){
            if(version1[i]!='.'){
                str += version1[i];
            }else{
                v1.push_back(stoi(str));
                str = "";
            }
        }
        
        v1.push_back(stoi(str));
        str = "";
        
        for(int i=0;i<version2.size();i++){
            if(version2[i]!='.'){
                str += version2[i];
            }else{
                v2.push_back(stoi(str));
                str = "";
            }
        }
        
        v2.push_back(stoi(str));
        str = "";
        
        if(v1.size()<v2.size()){
            int k = v1.size();
            while(k!=v2.size()){
                 v1.push_back(0);
                k++;
            }
        }else{
            int k = v2.size();
            while(k!=v1.size()){
                 v2.push_back(0);
                k++;
            }
        }
        
        int j = 0;
        while(j<v1.size()){
            if(v1[j]<v2[j]){
                return -1;
            }else if(v1[j]>v2[j]){
                if(j==0){
                    return 1;
                }
                if(flag==0){
                    return 1;
                }
                flag = 1;
            }else{
                flag = 0;
                j++;
                continue;
            }
            j++;
        }
        
        if(flag){
            return 1;
        }else{
            return 0;
        }
        
    }
};