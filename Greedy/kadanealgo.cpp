#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    int arr[10];

    int max_kadane = INT_MIN;
    int min_kadane = INT_MAX;

    int current_max = 0;
    int current_min = 0;

    for (int i = 0; i < num; i++)
    {
        // For maximum subarray sum (Kadane's algorithm)
        current_max = max(current_max + arr[i], arr[i]);
        max_kadane = max(max_kadane, current_max);

        // For minimum subarray sum (Kadane's algorithm)
        current_min = min(current_min + arr[i], arr[i]);
        min_kadane = min(min_kadane, current_min);
    }
}