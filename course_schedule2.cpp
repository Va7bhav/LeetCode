#include<iostream>
#include<vector>
using namespace std;
class Solution {
    bool dfs(vector<int> preMap[], int course, vector<int>& output, vector<int> visit, vector<int> cycle) {
        if(cycle[course]) return false;
        if(visit[course]) return true;
        cycle[course] = 1;
        for(auto pre : preMap[course]) {
            if(!dfs(preMap, pre, output, visit, cycle)) return false;
        }
        // course is now completed
        cycle[course] = 0;
        visit[course] = 1;
        output.push_back(course); 
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> output(numCourses);
        vector<int> visit(numCourses, 0); // this stores 1 if course is completed
        vector<int> cycle(numCourses, 0);
        vector<int> preMap[numCourses];
        for(auto vec : prerequisites) {
            preMap[vec[0]].push_back(vec[1]); //creating adjacency list of the graph, i.e for every course listing all the prerequisites
        }
        for(int course = 0; course < numCourses; course++) {
            if(!dfs(preMap, course, output, visit, cycle)) return {};
        }
        return output;
    }
};
int main() {
    
    return 0;
}