#include <bits/stdc++.h>
using namespace std;
int n;
map<int, int> prev_val;
int query(int index)
{
  if (prev_val.find(index) != prev_val.end())
    return prev_val[index];

  if (index == 0 || index == n + 1)
    return LLONG_MAX >> 1; // very big value

  cout << '?' << " " << index;
  int value;
  cin >> value;

  return prev_val[index] = value;
}
int main()
{
}