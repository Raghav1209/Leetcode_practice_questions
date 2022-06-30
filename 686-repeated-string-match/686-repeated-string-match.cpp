class Solution {
public:
    
    int base = 100000;
    int d = 31;
    
    int rabin_karp(string txt,string pat){
        int n = txt.size();
        int m = pat.size();
        int h = 1;
        for(int i=1;i<=m-1;i++){
            h = (h*d)%base;
        }
        
        int p=0;
        int t=0;
        
        for(int i=0;i<m;i++){
            p=(p*d+pat[i])%base;
            t=(t*d+txt[i])%base;
        }
        
        for(int i=0;i<=n-m;i++){
            if(p==t){
                bool flag = true;
                for(int j=0;j<m;j++){
                    if(txt[i+j]!=pat[j]){
                        flag = false;
                        break;
                    }
                }
                if(flag==true){
                    return i;
                }
            }
            
            if(i<n-m){
                t = ((d*(t-txt[i]*h))+txt[i+m])%base;
            }
            if(t<0){
                t = t+base;
            }
            
        }
        
        return -1;
        
        
    }
    
    int repeatedStringMatch(string a, string b) {
        
        if(a==b){
            return 1;
        }
        
        string source = a;
        int count = 1;
        while(source.size()<b.size()){
            count++;
            source += a;
        }
        
        if(source==b){
            return count;
        }
        
        if(rabin_karp(source,b)!=-1){
            return count;
        }
        
        if(rabin_karp(source+a,b)!=-1){
            return count+1;
        }
        
        return -1;
        
    }
};