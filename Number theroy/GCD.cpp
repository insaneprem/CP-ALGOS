#include <bits/stdc++.h>
using namespace std;
// int gcd(int a,int b){
//     if(a == 0) return b;

//     gcd(b%a,a);
// }

// int gcd(int a,int b){
//     return (b == 0 ? a : gcd(b,a%b));
// }
int main()
{
    // GCD(A,B)=GCD(B%A,A); WHEN A == 0 B IS ANSWER;
    cout << __gcd(10, 25);
}