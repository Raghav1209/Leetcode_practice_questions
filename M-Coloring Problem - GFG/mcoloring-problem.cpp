// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool isSafe(vector<int> &color,int k,bool graph[101][101],int node){
    
    for(int i=0;i<101;i++){
        if(graph[node][i]){
            if(color[i]==k){
                return false;
            }
        }
    }
    
    return true;
    
}

bool solve(bool graph[101][101],vector<int> &color,int n,int m,int node){
    
    if(node==color.size()){
        return true;
    }

        
        
            for(int k=0;k<m;k++){
                if(isSafe(color,k,graph,node)){
                    color[node] = k;
                    if(solve(graph,color,n,m,node+1)){
                        return true;
                    }
                    color[node] = -1;
                }
            }
            
            return false;
            
        
        
        
    
    
    
    
}

bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    
    vector<int> color(n,-1);
    bool res;
    for(int node=0;node<n;node++){
        if(color[node]==-1){
            res = solve(graph,color,n,m,node);
        }
        
        if(res==false){
            break;
        }
    }
    
    return res;
    
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends