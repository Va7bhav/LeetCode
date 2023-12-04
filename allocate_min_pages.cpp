#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool allocationIsPossible(int barrier, vector<int> pages, int students) {
    int allocatedStuds = 1;
    int _pages = 0;
    for(int i = 0; i < pages.size(); i++) {
        if(pages[i] > barrier) return false;

        if(_pages + pages[i] > barrier) {
            allocatedStuds += 1;
            _pages = 0; 
            _pages += pages[i];
        }
        
        else if(_pages + pages[i] <= barrier) {
            _pages += pages[i];
        }
    }
    if(allocatedStuds > students) return false;
    return true;

}

int Allocate(vector<int> pages, int students) {
    sort(pages.begin(), pages.end());
    int low = *max_element(pages.begin(), pages.end());
    int sumOfElements = 0;
    for(int element : pages) {
        sumOfElements += element;
    }
    int high = sumOfElements;
    int res = r;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(allocationIsPossible(mid, pages, students)) {
            res = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return res;
}
int main() {
    vector<int> pages {7, 2, 5, 10, 8};
    cout << Allocate(pages, 2); 
    return 0;
}