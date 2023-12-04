#include<iostream>
#include<vector>
using namespace std;

int maximum(int a, int b){
    return a>b?a:b;
}
int minimum(int a, int b){
    return a>b?b:a;
}

int main(){
    vector<int> v1{1, 3, 5, 7, 9, 11};
    vector<int> v2{1, 4, 5, 6, 9, 10, 13};
    vector<int> vin(minimum(v1.size(), v2.size()));

    vector<int> vun(maximum(v1.size(), v2.size())); 

    vector<int> :: iterator iter1; 
    vector<int> :: iterator iter2;
    vector<int> :: iterator iterin;
    vector<int> :: iterator iterun;

        iter1 = v1.begin();
        iter2 = v2.begin();
        int i;
    while(i < 42){
        i++;
        if(*iter1 < *iter2){
            iter1++;
        }
        else if(*iter1 > *iter2){
            iter2++;
        }
        else{
             vin.push_back(*iter1);
             iter1 ++;
             iter2 ++;
        }
    }
    for (int i = 0; i < vin.size(); i++)
    {
        cout<<vin[i];
    }
    return 0;

}