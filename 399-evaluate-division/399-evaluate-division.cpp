class Solution {
    unordered_map<string, vector<pair<string, double>>> adj;
    unordered_map<string, bool> visited;
    double queryAns;
public:
    
    bool findPath(string s,string d,double ans){
        if(adj.find(s)==adj.end() || adj.find(d)==adj.end()){
            return false;
        }
        
        if(s==d){
            queryAns = ans;
            return true;
        }
        vector<pair<string,double>> q = adj[s];
        bool tempAns = false;
        visited[s] = true;
    
        for(int i=0;i<q.size();i++){
            
            if(!visited[q[i].first]){
                tempAns = findPath(q[i].first,d,ans*q[i].second);
                if(tempAns){
                    break;
                }
            }
            
        }
        
        visited[s] = false;
        
        return tempAns;
        
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        
        int n = equations.size(), m = queries.size();
        vector<double> ans;
        
        for(int i=0;i<n;i++){
            vector<string> pair = equations[i];
            string source = pair[0];
            string destination = pair[1];
            
            adj[source].push_back({destination,values[i]});
            
            adj[destination].push_back({source,1/values[i]});
            visited[source] = false;
            visited[destination] = false;
        }
        // bool temp;
        for(int i=0;i<m;i++){
            queryAns = 1;
            vector<string> query = queries[i];
            string s = query[0];
            string d = query[1];
            
            if(!visited[s]){
                bool temp = findPath(s,d,1);
                
            if(temp){
                ans.push_back(queryAns);
            }else{
                    ans.push_back(-1);
                }
            }
            
        }
        
        return ans;
    }
};