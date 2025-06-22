#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    int l=0;
    while(n>>l) l++;
    cout<<l<<endl;
    cout<<log2(n);

    cout<<(~n & ((1<<l)-1))<<endl; //101->010
    cout<<~n; // -6(-(n+1)
}