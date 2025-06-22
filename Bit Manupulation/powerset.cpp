#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    //BRUTE FORCES TOO SLOW

    vector<int> arr(n);
    for(auto &i:arr) cin>>i;

    for(int bitmask = 0; bitmask < (1<<n) ; bitmask++ ){
        for(int j = 0 ; j < n ; j++ ){
            if( (bitmask >> j) & 1){
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
}