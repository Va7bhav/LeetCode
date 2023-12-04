#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

// the reason why we are using an actual stack instead of a vector is because
// we want topolgical sorting and we get it last in first out operation we wantthe top most items in the stack first in the resultant

// using DFS
class Solution {
void dfs(int i, int visit[], stack<int>& st, vector<int> adj[]) {
        visit[i] = 1;
        for(auto pre : adj[i]) {
            if(!visit[pre])
                dfs(pre, visit, st, adj);
        }
        st.push(i);
    }
	public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	    int visit[V] = {0};
        stack<int> st;
        for(int i = 0; i < V; i++) {
            if(!visit[i]) 
                dfs(i, visit, st, adj);
        }
        vector<int> res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
	}
};
// using BFS
class Solution {
	public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> indegree(V, 0);
        
        for (int i = 0; i < V; i+x  +) {
            for(auto it : adj[i]) indegree[it]++;
        }
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        // for (int i = 0; i < V; i++) {
        //     indegree[i] += adj[V].size();
        //     if (indegree[i] == 0) q.push(i);
        // }
        vector<int> res;
        while (!q.empty()) {
            int nodeVal = q.front(); 
            q.pop();
            res.push_back(nodeVal);
            
            for (int adjVal : adj[nodeVal]) {
                if (--indegree[adjVal] == 0) q.push(adjVal);
            }
        }
        return res;
	}
};
int main() {
    
    return 0;
}