class Solution {
public:
    
    static bool cmp(vector<string> &a,vector<string> &b){
        return stoi(a[0])<stoi(b[0]);
    }
    
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        
        set<string> s;
        set<string> ss;
        
        for(vector<string> info : orders){
            s.insert(info[2]);
            ss.insert(info[1]);
        }
        
        
        vector<vector<string>> ans(ss.size()+1,vector<string>(s.size()+1,"0"));
        
        ans[0][0] = "Table";
        map<string,int> mp2;
        int i = 1;
        for(auto x : s){
            ans[0][i] = x;
            mp2[x] = i;
            i++;
        }
    
        
        map<string,map<string,int>> mp;
        
        for(auto x : orders){
            string table_name = x[1];
            string food_item = x[2];
            mp[table_name][food_item]++;
        }
        
        // for(auto x : mp){
        //     cout<<x.first<<"->";
        //     for(auto y : x.second){
        //         cout<<y.first<<" "<<y.second<<endl;
        //     }
        //     cout<<endl;
        // }
        
        i=1;
        for(auto x : mp){
            ans[i][0] = x.first;
            for(auto y : x.second){
                ans[i][mp2[y.first]] = to_string(y.second);
            }
            i++;
        }
        
        sort(ans.begin()+1,ans.end(),cmp);
        
        return ans;
        
    }
};