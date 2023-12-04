#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool cycleCheck(int course, vector<int> preMap[], vector<int>& dfsVisit, vector<int>& visit) { 
        dfsVisit[course] = 1;
        visit[course] = 1;

        for(auto pre : preMap[course]) {  
            if(!visit[pre]) {
                if(cycleCheck(pre, preMap, dfsVisit, visit)) return true;
            }
            else if(dfsVisit[pre]) return true; // to detect cycle and return false
        }
        
        dfsVisit[course] = 0;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> preMap[numCourses];
        vector<int> dfsVisit (numCourses, 0);
        vector<int> visit (numCourses, 0);
        for(auto vec : prerequisites) {
            preMap[vec[0]].push_back(vec[1]); //creating adjacency list of the graph, i.e for every course listing all the prerequisites
        }

        for(int course = 0; course < numCourses; course++) {
            if(!visit[course]) {
                if(cycleCheck(course, preMap, dfsVisit, visit)) return false;    
            }
        }
        return true;
    }
};
class Solution2 {
    bool cycleCheck(int numCourses, vector<int> preMap[], int course, vector<int> currVisit, vector<int> cache) {
        cache[course] = 1;
        currVisit[course] = 1;
        for(auto pre : preMap[course]) {
            if(currVisit[pre]) {
                return true;  
            }
            else if(!cache[pre]) {
                if(cycleCheck(numCourses, preMap, pre, currVisit, cache)) return true;
            }
        }
        currVisit[course] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> preMap[numCourses];
        vector<int> currVisit;
        vector<int> cache;
        for(auto vec : prerequisites) {
            preMap[vec[0]].push_back(vec[1]); //creating adjacency list of the graph, i.e for every course listing all the prerequisites
        }
        for(int course = 0; course < numCourses; course++) {
            if(cycleCheck(numCourses, preMap, course, currVisit, cache)) return false;
        }
        return true;
    }
};

class Solution {
    bool cycleCheck(int course, vector<int> preMap[], vector<int> dfsvisit, vector<int> visit) {
        visit[course] = 1;
        dfsvisit[course] = 1;
        for(auto pre : preMap[course]) {
            if(!visit[pre])
                if(cycleCheck(pre, preMap, dfsvisit, visit)) return true;
            else {
                if(visit[pre]) return true;
                if(dfsvisit[pre]) return false;
            }
        }
        dfsvisit[course] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> preMap[numCourses];
        vector<int> dfsVisit (numCourses, 0);
        vector<int> visit (numCourses, 0);
        for(auto vec : prerequisites) {
            preMap[vec[0]].push_back(vec[1]); //creating adjacency list of the graph, i.e for every course listing all the prerequisites
        }

        for(int course = 0; course < numCourses; course++) {
            if(!visit[course]) {
                if(cycleCheck(course, preMap, dfsVisit, visit)) return false;    
            }
        }
        return true;
    }
};

int main() {
    
    return 0;
}