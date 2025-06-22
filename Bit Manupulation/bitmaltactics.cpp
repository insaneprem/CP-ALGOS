#include <bits/stdc++.h>
using namespace std;
//Compute XOR from 1 to n (direct method):
int computeXOR(int n)
{
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    else return 0;
}
//Count of numbers (x) smaller than or equal to n such that n+x = n^x:
//Property (a+b)=(a^b)+(a&b);
int countValues(int n)
{
    // unset_bits keeps track of count of un-set
    // bits in binary representation of n
    int unset_bits=0;
    while (n)
    {
        if ((n & 1) == 0)
            unset_bits++;
        n=n>>1;
    }
 
    // Return 2 ^ unset_bits
    return 1 << unset_bits;
}
//Convert binary code directly into an integer in C++
int b2d(int num){
    // return 0bnum;
}

//Check if a number has bits in an alternate pattern
//Compute bitwise XOR (XOR denoted using ^) of n and (n >> 1). 
//If n has an alternate pattern, then n ^ (n >> 1) operation will produce a number having all bits set.
static bool allBitsAreSet(int n)
{
    if (((n + 1) & n) == 0) return true;
    return false;
}

// Function to check if a number has bits in alternate pattern
bool bitsAreInAltOrder(unsigned int n)
{
    unsigned int num = n ^ (n >> 1);
    return allBitsAreSet(num);
}
//------------------------------------------------------------------------------->


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    // Number of leading zeroes: __builtin_clz(x)
    // a = 16
    // Binary form of 16 is 00000000 00000000 00000000 00010000
    // Output: 27

    // Number of trailing zeroes : __builtin_ctz(x)
    // a = 16
    // Binary form of 16 is 00000000 00000000 00000000 00010000
    // Output: ctz = 4
    
    // Number of 1-bits: __builtin_popcount(x) 
    
}