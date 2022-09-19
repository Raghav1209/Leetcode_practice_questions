class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        int n = paths.size();
        map<string,vector<string>> mp;
        
        for(int i=0;i<paths.size();i++){
            
            string directoryInfo = paths[i];
            stringstream ss(directoryInfo);
            string s,dir;
            bool firstWord = true;
            
            while(getline(ss,s,' ')){
                if(firstWord){
                    dir = s;
                    firstWord = false;
                }else{
                    int i = 0;
                    int fileNameLen = 0;
                    while(i<s.size() && s[i++]!='('){
                        fileNameLen++;
                        // i++;
                    }
                    string fileName;
                    fileName = s.substr(0,fileNameLen);
                    // cout<<fileName<<endl;
                    int j = fileNameLen+1;
                    int fileContentLen = 0;
                    while(j<s.size() && s[j++]!=')'){
                        fileContentLen++;
                        // j++;
                    }
                    
                    string fileContentName;
                    fileContentName = s.substr(fileNameLen+1,fileContentLen);
                    // cout<<fileContentName<<endl;
                     mp[fileContentName].push_back(dir+"/"+fileName);
                    
                }
                
               
                
            }
            
        }
        vector<vector<string>> ans;
        for(auto x : mp){
            vector<string> vc = x.second;
            if(vc.size()==1){
                continue;
            }
            ans.push_back(vc);
        }
        
        return ans;
        
    }
};