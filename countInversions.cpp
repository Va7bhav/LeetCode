#include<iostream>
#include<vector>
using namespace std;

void merge(int left, int right, vector<int>& arr, int& countInversion) {
    int mid = (left + right) / 2;

    vector<int> first(mid - left + 1);
    vector<int> second(right - mid);    

    int arrIndex = left;
    for(int i = 0; i < first.size(); i++) {
        first[i] = arr[arrIndex++];
    }
    for(int j = 0; j < second.size(); j++) {
        second[j] = arr[arrIndex++];
    }

    int i = 0, j = 0; arrIndex = left;
    while(i < first.size() && j < second.size()) {      
        if(first[i] < second[j]) { 
            arr[arrIndex++] = first[i++];
        }
        else {
            countInversion += first.size() - i;
            arr[arrIndex++] = second[j++];
        }
    }
    while(i < first.size()) {
        arr[arrIndex++] = first[i++];
    }
    while(j < second.size()) {
        arr[arrIndex++] = second[j++];
    }
}
int mergeSortCountInversion(int left, int right, vector<int>& arr) {
    static int countInversion = 0;
    if(right > left) {
        int mid = (left + right) / 2;
        mergeSortCountInversion(left, mid, arr);
        mergeSortCountInversion(mid + 1, right, arr);
        merge(left, right, arr, countInversion);
    }
    return countInversion;
}
// void merge(int left, int right, vector<int>& arr) {
//     int mid = (left + right) / 2;

//     vector<int> first(mid - left + 1);
//     vector<int> second(right - mid);    

//     int arrIndex = left;
//     for(int i = 0; i < first.size(); i++) {
//         first[i] = arr[arrIndex++];
//     }
//     for(int j = 0; j < second.size(); j++) {
//         second[j] = arr[arrIndex++];
//     }

//     int i = 0, j = 0; arrIndex = left;
//     while(i < first.size() && j < second.size()) {      
//         if(first[i] < second[j]) { 
//             arr[arrIndex++] = first[i++];
//         }
//         else {
//             arr[arrIndex++] = second[j++];
//         }
//     }
//     while(i < first.size()) {
//         arr[arrIndex++] = first[i++];
//     }
//     while(j < second.size()) {
//         arr[arrIndex++] = second[j++];
//     }
// }
// void mergeSortCountInversion(int left, int right, vector<int>& arr) {
//     if(right > left) {
//         int mid = (left + right) / 2;
//         mergeSortCountInversion(left, mid, arr);
//         mergeSortCountInversion(mid + 1, right, arr);
//         merge(left, right, arr);
//     }
// }
int main() {
    vector<int> arr {0};
    cout << mergeSortCountInversion(0, arr.size() - 1, arr) << endl;   
    // for(auto element : arr) {
    //     cout << element << " ";
    // } cout << endl;

    return 0;
}