#include <bits/stdc++.h>
using namespace std;
//SET NTH BIT
void set(int num,int pos){
    num=num | (1<<pos);
}
//CLEAT BIT AT NTH POS
void unset(int num,int pos){
    num= num & (~ (1 << pos) );
}
//TOGGLE BIT AT NTH POS
void toggle(int num,int pos){
    num= num ^(1<<pos);
}
//CHECK ID NTH BIT IS SET OR NOT
bool at_position(int num, int pos)
{
    bool bit = num & (1 << pos);
    return bit;
}
//STRIPPING OF LOWEST SET BIT FROM LEFT
void strip_last_set_bit(int &num)
{
    num = num & (num-1);
}
//Getting the lowest set bit of a number:
// This is done by using the expression ‘X &(-X)’ So ~X(1’s complement) 
// will be ‘11010011’ and 2’s complement will be (~X+1 or -X) i.e.  ‘11010100’

//   00101100
// & 11010100
// -----------
//   00000100

int lowest_set_bit(int num)
{
    int ret = num & (-num);
    return ret;

    //RET IS THE NUMBER 100 FOR INDEX TAKE LOG2
}

//count set bit
int countSetBits(int x)
{
    int count = 0;
    while (x)
    {
        x &= (x-1);
        //Strping of last set bit
        count++;
    }
    return count;
}

//Lower case to upper case
// ch &= '_’ ;
// Example: 
// ch = ‘a’ (01100001) 
// mask = ‘_ ‘ (11011111) 
// ch & mask = ‘A’ (01000001) 

//Upper case English alphabet to lower case 
//ch |= ' ';
// Example: 
// ch = ‘A’ (01000001) 
// mask = ‘ ‘ (00100000) 
// ch | mask = ‘a’ (01100001) 

//Clear all bits from LSB to ith bit 
// mask = ~((1 << i+1 ) - 1);
// x &= mask;


// Clearing all bits from MSB to i-th bit 
// mask = (1 << i) - 1;
// x &= mask;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout<<log2(5);
}