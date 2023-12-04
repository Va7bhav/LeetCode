#include<iostream>
using namespace std;

int number_of_steps(int n)
{
    if(n==0) return 1;
    if(n==1) return 1;
    return number_of_steps(n-1) + number_of_steps(n-2);
}

int main(){
    int ans = number_of_steps(44);
    cout<<ans;
    return 0;
}
