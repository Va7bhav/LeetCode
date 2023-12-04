#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 
void show(vector<int> const &input) {
    for (auto const& i: input) {
        std::cout << i << " ";
    }
}
int main() {
   vector<int> v1 = { 1, 2, 3 };
   vector<int> v2 = { 4, 5 };
   v2.insert(v2.end(), v1.begin(), v1.begin() + 1);
   cout<<"Resultant vector is:"<<endl;
   show(v2);
   return 0;
}
