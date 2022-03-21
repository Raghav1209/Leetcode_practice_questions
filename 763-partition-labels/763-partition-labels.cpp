class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n = s.length();
        unordered_map<int,int> last;
        vector<int> v;
        int i,j;
        unordered_map<int,int> mp;
        int k = 0;
        int flag = 1;
        
        for(int l=0;l<n;l++){
            mp[s[l]]++;
            last[s[l]] = l;
        }
        
        for(i=0;i<n;i++){
            mp[s[i]]--;
            if(last[s[i]]==i){
                for(j=k;j<=i;j++){
                    if(mp[s[j]]!=0){
                        flag = 0;
                        break;
                    }
                }
                if(flag){
                    // string str = s.substr(k,i);
                    string str = "";
                    for(int m=k;m<=i;m++){
                        str += s[m];
                    }
                    cout<<str<<" ";
                    v.push_back(str.length());
                    k = i+1;
                }
                
                 flag = 1;
                
            }
        }
        
        return v;
        
    
        
    }
};